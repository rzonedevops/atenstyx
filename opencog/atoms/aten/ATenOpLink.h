/*
 * ATenOpLink.h
 *
 * ATen Operation Link - executable tensor operations
 * Part of the ATenStyx neuro-symbolic cognitive fabric
 *
 * Copyright (C) 2026 OpenCog Foundation
 * SPDX-License-Identifier: AGPL-3.0-or-later
 */

#ifndef _OPENCOG_ATEN_OP_LINK_H
#define _OPENCOG_ATEN_OP_LINK_H

#include <opencog/atoms/core/FunctionLink.h>

namespace opencog
{
/** \addtogroup grp_atomspace
 *  @{
 */

/**
 * The ATenOpLink represents executable tensor operations.
 * It extends FunctionLink to enable tensor computations as
 * part of the symbolic execution framework.
 *
 * The first atom specifies the operation (add, mul, matmul, etc)
 * and subsequent atoms are the operands.
 *
 * Example:
 *   (ATenOpLink
 *     (Concept "matmul")
 *     (ATenNode "weights")
 *     (ATenNode "input"))
 */
class ATenOpLink : public FunctionLink
{
protected:
	void init(void);

public:
	ATenOpLink(const HandleSeq&, Type = ATEN_OP_LINK);
	ATenOpLink(const Handle& op, const Handle& a);
	ATenOpLink(const Handle& op, const Handle& a, const Handle& b);
	ATenOpLink(const Link&);

	static Handle factory(const Handle&);

	// Execute the tensor operation
	virtual ValuePtr execute(AtomSpace*, bool silent=false);
};

typedef std::shared_ptr<ATenOpLink> ATenOpLinkPtr;
static inline ATenOpLinkPtr ATenOpLinkCast(const Handle& h)
	{ return std::dynamic_pointer_cast<ATenOpLink>(h); }
static inline ATenOpLinkPtr ATenOpLinkCast(AtomPtr a)
	{ return std::dynamic_pointer_cast<ATenOpLink>(a); }

#define createATenOpLink std::make_shared<ATenOpLink>

/** @}*/
}

#endif // _OPENCOG_ATEN_OP_LINK_H
