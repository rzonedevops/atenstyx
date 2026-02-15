/*
 * ATenNode.cc
 *
 * ATen Tensor Node implementation
 * Part of the ATenStyx neuro-symbolic cognitive fabric
 *
 * Copyright (C) 2026 OpenCog Foundation
 * SPDX-License-Identifier: AGPL-3.0-or-later
 */

#include "ATenNode.h"
#include <opencog/atoms/atom_types/atom_types.h>

using namespace opencog;

// Register the factory for ATenNode
DEFINE_NODE_FACTORY(ATenNode, ATEN_NODE)
