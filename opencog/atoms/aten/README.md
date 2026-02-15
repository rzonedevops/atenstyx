# ATen Atom Extensions

This module extends the AtomSpace with ATen (A Tensor Library) integration,
enabling neuro-symbolic computing by bridging tensor operations with symbolic
knowledge representation.

## Overview

ATen (https://github.com/zdevito/ATen) is a tensor library that provides the
computational backend for PyTorch. This extension allows AtomSpace atoms to
represent and manipulate tensors directly, enabling:

- **Symbolic-Numeric Integration**: Seamlessly combine symbolic reasoning with
  neural network computations
- **Tensor Knowledge Representation**: Store and query tensor data within the
  hypergraph structure
- **Differentiable Knowledge Graphs**: Apply gradient-based learning to
  knowledge representations

## Atom Types

### ATenNode
Represents a tensor value or tensor operation in the AtomSpace.

```scheme
(ATenNode "my_tensor")  ; Named tensor reference
```

### ATenTensorLink
Links representing tensor operations that can be executed.

```scheme
(ATenTensorLink
  (ATenNode "input1")
  (ATenNode "input2"))
```

### ATenOpLink
Links representing specific tensor operations (add, multiply, etc.).

```scheme
(ATenOpLink
  (Concept "add")
  (ATenNode "tensor1")
  (ATenNode "tensor2"))
```

## Values

### TensorValue
A Value type that stores actual tensor data, attached to atoms as key-value pairs.

## Integration with Neuro-Symbolic Processing

The ATen extension enables:
1. **Forward propagation**: Execute tensor operations through atom execution
2. **Backward propagation**: Gradient flow through symbolic structures
3. **Hybrid reasoning**: Combine pattern matching with neural computations
4. **Knowledge distillation**: Extract symbolic rules from trained networks

## Usage Example

```python
from opencog.atomspace import AtomSpace, types
from opencog.atoms.aten import TensorValue

atomspace = AtomSpace()

# Create tensor atom
tensor_node = atomspace.add_node(types.ATenNode, "weights")

# Attach tensor data
import torch
tensor_data = torch.randn(3, 3)
tensor_node.set_value(types.ATenKey, TensorValue(tensor_data))

# Create tensor operation
op_link = atomspace.add_link(types.ATenOpLink,
    atomspace.add_node(types.ConceptNode, "matmul"),
    tensor_node,
    atomspace.add_node(types.ATenNode, "input"))

# Execute operation
result = op_link.execute(atomspace)
```

## Building

The ATen extension is built as part of the main AtomSpace build. Ensure ATen/PyTorch
headers are available in your system.

## See Also

- [AtomSpace Documentation](../../README.md)
- [Styx Space Extensions](../../atomspace/styx/README.md)
- [Neuro-Symbolic Fabric](../../../doc/neuro-symbolic.md)
