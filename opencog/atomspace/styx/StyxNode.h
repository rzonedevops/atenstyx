/*
 * StyxNode.h
 *
 * Styx Protocol Node - represents a Styx/9P endpoint
 * Part of the ATenStyx neuro-symbolic cognitive fabric
 *
 * Copyright (C) 2026 OpenCog Foundation
 * SPDX-License-Identifier: AGPL-3.0-or-later
 */

#ifndef _OPENCOG_STYX_NODE_H
#define _OPENCOG_STYX_NODE_H

#include <opencog/atoms/base/Node.h>

namespace opencog
{
/** \addtogroup grp_atomspace
 *  @{
 */

/**
 * The StyxNode represents a Styx/9P protocol endpoint.
 * It enables network-transparent access to distributed AtomSpaces
 * using the Plan 9 file protocol.
 *
 * The node name typically contains a URI specifying the endpoint:
 *   tcp://hostname:port
 *   unix:///path/to/socket
 *
 * Example:
 *   (StyxNode "tcp://cluster1.example.com:564")
 *   (StyxNode "unix:///var/run/atomspace.9p")
 */
class StyxNode : public Node
{
public:
	StyxNode(Type t, const std::string& name)
		: Node(t, name)
	{
		if (not nameserver().isA(t, STYX_NODE))
			throw InvalidParamException(TRACE_INFO,
				"Expecting a StyxNode");
	}

	StyxNode(const std::string& name)
		: Node(STYX_NODE, name)
	{}

	static Handle factory(const Handle& h)
	{
		if (h->is_node())
			return createStyxNode(h->get_type(), h->get_name());
		return h;
	}
};

typedef std::shared_ptr<StyxNode> StyxNodePtr;
static inline StyxNodePtr StyxNodeCast(const Handle& h)
	{ return std::dynamic_pointer_cast<StyxNode>(h); }
static inline StyxNodePtr StyxNodeCast(AtomPtr a)
	{ return std::dynamic_pointer_cast<StyxNode>(a); }

#define createStyxNode std::make_shared<StyxNode>

/** @}*/
}

#endif // _OPENCOG_STYX_NODE_H
