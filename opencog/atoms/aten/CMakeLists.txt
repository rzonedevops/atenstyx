# ATen Tensor Extensions for AtomSpace
# Integration with ATen (A Tensor Library) for neuro-symbolic computing

ADD_LIBRARY(aten SHARED
	ATenNode.cc
	ATenTensorLink.cc
	ATenOpLink.cc
)

TARGET_LINK_LIBRARIES(aten
	atombase
	${COGUTIL_LIBRARY}
)

INSTALL(TARGETS aten
	EXPORT AtomSpaceTargets
	DESTINATION "lib${LIB_DIR_SUFFIX}/opencog"
)

INSTALL(FILES
	ATenNode.h
	ATenTensorLink.h
	ATenOpLink.h
	DESTINATION "include/opencog/atoms/aten"
)
