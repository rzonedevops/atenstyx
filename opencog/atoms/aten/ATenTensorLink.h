/*
 * ATenTensorLink.h
 *
 * ATen Tensor Link - represents tensor computation graphs
 * Part of the ATenStyx neuro-symbolic cognitive fabric
 *
 * Copyright (C) 2026 OpenCog Foundation
 * SPDX-License-Identifier: AGPL-3.0-or-later
 */

#ifndef _OPENCOG_ATEN_TENSOR_LINK_H
#define _OPENCOG_ATEN_TENSOR_LINK_H

#include <opencog/atoms/base/Link.h>

namespace opencog
{
/** \addtogroup grp_atomspace
 *  @{
 */

/**
 * The ATenTensorLink represents connections in a tensor computation graph.
 * It enables building symbolic representations of neural network
 * architectures and data flow.
 *
 * Example:
 *   (ATenTensorLink
 *     (ATenNode "input")
 *     (ATenNode "hidden_layer"))
 */
class ATenTensorLink : public Link
{
public:
	ATenTensorLink(const HandleSeq& oset, Type t = ATEN_TENSOR_LINK)
		: Link(oset, t)
	{
		if (not nameserver().isA(t, ATEN_TENSOR_LINK))
			throw InvalidParamException(TRACE_INFO,
				"Expecting an ATenTensorLink");
	}

	ATenTensorLink(const Handle& a, const Handle& b)
		: Link({a, b}, ATEN_TENSOR_LINK)
	{}

	static Handle factory(const Handle& h)
	{
		return createATenTensorLink(h->getOutgoingSet(), h->get_type());
	}
};

typedef std::shared_ptr<ATenTensorLink> ATenTensorLinkPtr;
static inline ATenTensorLinkPtr ATenTensorLinkCast(const Handle& h)
	{ return std::dynamic_pointer_cast<ATenTensorLink>(h); }
static inline ATenTensorLinkPtr ATenTensorLinkCast(AtomPtr a)
	{ return std::dynamic_pointer_cast<ATenTensorLink>(a); }

#define createATenTensorLink std::make_shared<ATenTensorLink>

/** @}*/
}

#endif // _OPENCOG_ATEN_TENSOR_LINK_H
