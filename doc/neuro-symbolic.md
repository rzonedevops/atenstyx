# ATenStyx Neuro-Symbolic Cognitive Fabric

## Overview

The ATenStyx framework synthesizes two powerful extensions to the OpenCog AtomSpace:

1. **ATen Integration** (atoms/aten): Extends "atom" with tensor operations from ATen (A Tensor Library)
2. **Styx Protocol** (atomspace/styx): Extends "space" with Plan 9 Styx/9P distributed access protocol

Together, these create a **neuro-symbolic cognitive fabric** that enables:
- Symbolic reasoning over neural network structures
- Distributed knowledge representation
- Transparent integration of neural and symbolic computation
- Network-accessible hypergraph databases

## Architecture

```
┌─────────────────────────────────────────────────────────┐
│              Neuro-Symbolic Cognitive Fabric            │
├─────────────────────────────────────────────────────────┤
│                                                         │
│  ┌──────────────────┐         ┌──────────────────┐    │
│  │   ATen Atoms     │         │   Styx Space     │    │
│  │  (Neural Layer)  │ ◄─────► │ (Network Layer)  │    │
│  └──────────────────┘         └──────────────────┘    │
│         │                              │               │
│         └──────────┬───────────────────┘               │
│                    ▼                                   │
│         ┌──────────────────┐                          │
│         │   AtomSpace      │                          │
│         │ (Symbolic Layer) │                          │
│         └──────────────────┘                          │
│                                                         │
└─────────────────────────────────────────────────────────┘
```

## ATen: Neural Extension of Atoms

ATen (from https://github.com/zdevito/ATen) provides the tensor computation backend for PyTorch. By integrating ATen with AtomSpace atoms, we enable:

### Tensor Atoms
- **ATenNode**: Named tensor references
- **ATenTensorLink**: Tensor computation graph connections
- **ATenOpLink**: Executable tensor operations

### Use Cases
1. **Knowledge Graph Embeddings**: Store learned embeddings directly in atoms
2. **Differentiable Reasoning**: Apply gradient descent to symbolic structures
3. **Neural-Symbolic Translation**: Convert between tensor and symbolic representations
4. **Hybrid Models**: Seamlessly mix neural networks with logical inference

### Example: Neural Pattern Matching
```scheme
; Define a tensor-based similarity operation
(define weights
  (ATenNode "similarity_weights"))

; Pattern with neural scoring
(Get
  (Variable "$entity")
  (And
    (Inheritance (Variable "$entity") (Concept "Person"))
    (GreaterThan
      (ATenOpLink
        (Concept "similarity")
        (Variable "$entity")
        weights)
      (Number 0.8))))
```

## Styx: Network Extension of Space

Styx is the 9P file protocol from Plan 9, designed for transparent distributed access. By exposing the AtomSpace via Styx, we enable:

### Protocol Atoms
- **StyxNode**: Network endpoint addresses
- **StyxSpaceLink**: Distributed space connections
- **StyxRemoteLink**: Remote execution operations

### Use Cases
1. **Federated Knowledge**: Share atoms across multiple systems
2. **Distributed Reasoning**: Query patterns across network clusters
3. **Remote Execution**: Execute atoms on specialized hardware
4. **Universal Access**: Use standard tools (mount, cat, echo) to manipulate atoms

### File System Mapping
```
/atomspace/
  /atoms/               # UUID-indexed atoms
    /12345/
      /type            # "ConceptNode"
      /name            # "AI"
      /incoming        # List of links containing this atom
      /values/         # Key-value attachments
  /types/              # Type-indexed atoms
    /ConceptNode/
    /ATenNode/
  /queries/            # Pattern matching interface
  /execute/            # Remote execution
```

### Example: Distributed Query
```bash
# Mount remote atomspace
9pfuse tcp!cluster1!564 /mnt/remote

# Query remote concepts
cat /mnt/remote/types/ConceptNode/ | head -10

# Execute pattern remotely
echo "(Get (Variable \$x) (Concept \$x))" > /mnt/remote/queries/all_concepts
cat /mnt/remote/queries/all_concepts
```

## Neuro-Symbolic Integration

The power emerges when combining both extensions:

### 1. Distributed Neural Processing
```scheme
; Create tensor on remote GPU cluster
(StyxRemoteLink
  (StyxNode "tcp://gpu-cluster:564")
  (ATenOpLink
    (Concept "train")
    (ATenNode "model")
    (ATenNode "dataset")))
```

### 2. Symbolic Control of Neural Nets
```scheme
; Rule-based neural architecture search
(Bind
  (Variable "$architecture")
  (And
    (Evaluation (Predicate "valid_architecture") (Variable "$architecture"))
    (GreaterThan
      (ATenOpLink (Concept "evaluate") (Variable "$architecture"))
      (Number 0.95)))
  (ATenOpLink (Concept "deploy") (Variable "$architecture")))
```

### 3. Knowledge Distillation
```scheme
; Extract symbolic rules from neural model
(FilterLink
  (Lambda (Variable "$rule")
    (GreaterThan
      (ATenOpLink (Concept "confidence") (Variable "$rule"))
      (Number 0.9)))
  (ATenOpLink (Concept "extract_rules") (ATenNode "trained_model")))
```

### 4. Distributed Learning
```bash
# Share learned embeddings across cluster
9pfuse tcp!node1!564 /mnt/node1
9pfuse tcp!node2!564 /mnt/node2

# Sync ATen tensors
cp /mnt/node1/atoms/*/values/tensor /mnt/node2/atoms/*/values/tensor
```

## Implementation Status

### Completed ✓
- Atom type definitions (ATenNode, ATenTensorLink, ATenOpLink)
- Space type definitions (StyxNode, StyxSpaceLink, StyxRemoteLink)
- Basic C++ class implementations
- Documentation framework

### Future Work
- Full ATen tensor integration (requires ATen/PyTorch libraries)
- Complete Styx/9P protocol implementation (requires plan9port)
- TensorValue type for storing tensor data
- StyxConnectionValue for managing connections
- Python bindings for both extensions
- Example applications demonstrating neuro-symbolic reasoning
- Performance benchmarks

## Building

The extensions are integrated into the AtomSpace build system:

```bash
mkdir build && cd build
cmake ..
make -j
sudo make install
```

Optional dependencies:
- PyTorch/ATen: For full tensor support
- plan9port: For Styx protocol implementation

## References

- [ATen GitHub](https://github.com/zdevito/ATen)
- [Plan 9 Documentation](https://9p.io/plan9/)
- [AtomSpace Documentation](../README.md)
- [OpenCog Wiki](https://wiki.opencog.org/)

## Contributing

This framework provides the foundation for neuro-symbolic AI research. Contributions welcome:
- Tensor operation implementations
- Protocol handlers for Styx
- Example applications
- Performance optimizations
- Integration with existing neural network frameworks

## License

AGPL-3.0-or-later (consistent with OpenCog AtomSpace)
