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
#include "clutter/clutter-transition.h"

G_BEGIN_DECLS

#define CLUTTER_TYPE_PROPERTY_TRANSITION                (clutter_property_transition_get_type ())

CLUTTER_EXPORT
G_DECLARE_DERIVABLE_TYPE (ClutterPropertyTransition,
                          clutter_property_transition,
                          CLUTTER,
                          PROPERTY_TRANSITION,
                          ClutterTransition)

/**
 * ClutterPropertyTransitionClass:
 *
 * The #ClutterPropertyTransitionClass structure
 * contains private data.
 */
struct _ClutterPropertyTransitionClass
{
  /*< private >*/
  ClutterTransitionClass parent_class;
};

CLUTTER_EXPORT
ClutterTransition *     clutter_property_transition_new_for_actor       (ClutterActor              *actor,
                                                                         const char                *property_name);

CLUTTER_EXPORT
ClutterTransition *     clutter_property_transition_new                 (const char                *property_name);

CLUTTER_EXPORT
void                    clutter_property_transition_set_property_name   (ClutterPropertyTransition *transition,
                                                                         const char                *property_name);
CLUTTER_EXPORT
const char *            clutter_property_transition_get_property_name   (ClutterPropertyTransition *transition);

G_END_DECLS
