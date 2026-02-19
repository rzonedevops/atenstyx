# Styx Protocol Extensions for AtomSpace
# Integration with Plan 9 Styx/9P for distributed space access

ADD_LIBRARY(styx SHARED
	StyxNode.cc
	StyxSpaceLink.cc
	StyxRemoteLink.cc
)

TARGET_LINK_LIBRARIES(styx
	atomspace
	atombase
	${COGUTIL_LIBRARY}
)

INSTALL(TARGETS styx
	EXPORT AtomSpaceTargets
	DESTINATION "lib${LIB_DIR_SUFFIX}/opencog"
)

INSTALL(FILES
	StyxNode.h
	StyxSpaceLink.h
	StyxRemoteLink.h
	DESTINATION "include/opencog/atomspace/styx"
)
