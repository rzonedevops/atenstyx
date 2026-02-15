/*
 * ATenNode.h
 *
 * ATen Tensor Node - represents a named tensor in the AtomSpace
 * Part of the ATenStyx neuro-symbolic cognitive fabric
 *
 * Copyright (C) 2026 OpenCog Foundation
 * SPDX-License-Identifier: AGPL-3.0-or-later
 */

#ifndef _OPENCOG_ATEN_NODE_H
#define _OPENCOG_ATEN_NODE_H

#include <opencog/atoms/base/Node.h>

namespace opencog
{
/** \addtogroup grp_atomspace
 *  @{
 */

/**
 * The ATenNode represents a named tensor in the AtomSpace.
 * It extends the atom model to support tensor operations for
 * neuro-symbolic computing.
 *
 * ATenNodes can store references to tensor data via TensorValue
 * attachments, enabling integration between symbolic reasoning
 * and neural network computations.
 *
 * Example:
 *   (ATenNode "weights_layer1")
 *   (ATenNode "activations")
 */
class ATenNode : public Node
{
public:
	ATenNode(Type t, const std::string& name)
		: Node(t, name)
	{
		if (not nameserver().isA(t, ATEN_NODE))
			throw InvalidParamException(TRACE_INFO,
				"Expecting an ATenNode");
	}

	ATenNode(const std::string& name)
		: Node(ATEN_NODE, name)
	{}

	static Handle factory(const Handle& h)
	{
		if (h->is_node())
			return createATenNode(h->get_type(), h->get_name());
		return h;
	}
};

typedef std::shared_ptr<ATenNode> ATenNodePtr;
static inline ATenNodePtr ATenNodeCast(const Handle& h)
	{ return std::dynamic_pointer_cast<ATenNode>(h); }
static inline ATenNodePtr ATenNodeCast(AtomPtr a)
	{ return std::dynamic_pointer_cast<ATenNode>(a); }

#define createATenNode std::make_shared<ATenNode>

/** @}*/
}

#endif // _OPENCOG_ATEN_NODE_H
