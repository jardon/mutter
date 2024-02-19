/*
 * Clutter.
 *
 * An OpenGL based 'interactive canvas' library.
 *
 * Copyright (C) 2012 Intel Corporation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Emmanuele Bassi <ebassi@linux.intel.com>
 */

#pragma once

#if !defined(__CLUTTER_H_INSIDE__) && !defined(CLUTTER_COMPILATION)
#error "Only <clutter/clutter.h> can be included directly."
#endif

#include "clutter/clutter-types.h"
#include "clutter/clutter-timeline.h"

G_BEGIN_DECLS

#define CLUTTER_TYPE_TRANSITION                 (clutter_transition_get_type ())

CLUTTER_EXPORT
G_DECLARE_DERIVABLE_TYPE (ClutterTransition,
                          clutter_transition,
                          CLUTTER,
                          TRANSITION,
                          ClutterTimeline)

/**
 * ClutterTransitionClass:
 * @attached: virtual function; called when a transition is attached to
 *   a #ClutterAnimatable instance
 * @detached: virtual function; called when a transition is detached from
 *   a #ClutterAnimatable instance
 * @compute_value: virtual function; called each frame to compute and apply
 *   the interpolation of the interval
 *
 * The #ClutterTransitionClass structure contains
 * private data.
 */
struct _ClutterTransitionClass
{
  /*< private >*/
  ClutterTimelineClass parent_class;

  /*< public >*/
  void (* attached) (ClutterTransition *transition,
                     ClutterAnimatable *animatable);
  void (* detached) (ClutterTransition *transition,
                     ClutterAnimatable *animatable);

  void (* compute_value) (ClutterTransition *transition,
                          ClutterAnimatable *animatable,
                          ClutterInterval   *interval,
                          gdouble            progress);
};

CLUTTER_EXPORT
void                    clutter_transition_set_interval                 (ClutterTransition *transition,
                                                                         ClutterInterval   *interval);
CLUTTER_EXPORT
ClutterInterval *       clutter_transition_get_interval                 (ClutterTransition *transition);
CLUTTER_EXPORT
void                    clutter_transition_set_from_value               (ClutterTransition *transition,
                                                                         const GValue      *value);
CLUTTER_EXPORT
void                    clutter_transition_set_to_value                 (ClutterTransition *transition,
                                                                         const GValue      *value);
CLUTTER_EXPORT
void                    clutter_transition_set_from                     (ClutterTransition *transition,
                                                                         GType              value_type,
                                                                         ...);
CLUTTER_EXPORT
void                    clutter_transition_set_to                       (ClutterTransition *transition,
                                                                         GType              value_type,
                                                                         ...);

CLUTTER_EXPORT
void                    clutter_transition_set_animatable               (ClutterTransition *transition,
                                                                         ClutterAnimatable *animatable);
CLUTTER_EXPORT
ClutterAnimatable *     clutter_transition_get_animatable               (ClutterTransition *transition);
CLUTTER_EXPORT
void                    clutter_transition_set_remove_on_complete       (ClutterTransition *transition,
                                                                         gboolean           remove_complete);
CLUTTER_EXPORT
gboolean                clutter_transition_get_remove_on_complete       (ClutterTransition *transition);

G_END_DECLS
