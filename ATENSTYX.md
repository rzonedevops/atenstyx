# ATenStyx: Neuro-Symbolic Cognitive Fabric

This repository extends the OpenCog AtomSpace with the **ATenStyx** framework,
a neuro-symbolic cognitive fabric that synthesizes:

1. **ATen Integration** ([github.com/zdevito/ATen](https://github.com/zdevito/ATen)) - Extension of "atom"
2. **Plan 9 Styx Protocol** - Extension of "space"

## What is ATenStyx?

ATenStyx creates a unified framework for neuro-symbolic AI by:

```
┌─────────────────────────────────────────────────────────┐
│              Neuro-Symbolic Cognitive Fabric            │
├─────────────────────────────────────────────────────────┤
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
└─────────────────────────────────────────────────────────┘
```

### ATen Extension: Neural "Atoms"

ATen (A Tensor Library) is the computational backend for PyTorch. By integrating
ATen with atoms, we enable:

- **Tensor representation in knowledge graphs**
- **Differentiable reasoning** over symbolic structures
- **Neural-symbolic translation** between continuous and discrete representations
- **Gradient-based learning** on hypergraph structures

**New Atom Types:**
- `ATenNode` - Named tensor references
- `ATenTensorLink` - Tensor computation graph connections
- `ATenOpLink` - Executable tensor operations

**Example:**
```scheme
; Neural pattern matching with tensor scoring
(Get
  (Variable "$entity")
  (And
    (Inheritance (Variable "$entity") (Concept "Person"))
    (GreaterThan
      (ATenOpLink
        (Concept "similarity")
        (Variable "$entity")
        (ATenNode "query_embedding"))
      (Number 0.8))))
```

See [opencog/atoms/aten/README.md](opencog/atoms/aten/README.md) for details.

### Styx Extension: Distributed "Space"

Styx (9P) is the Plan 9 file protocol designed for transparent distributed access.
By exposing the AtomSpace via Styx, we enable:

- **Network-transparent knowledge access** using standard file tools
- **Federated reasoning** across distributed systems
- **Remote execution** of symbolic computations
- **Universal access** via mount, cat, echo operations

**New Atom Types:**
- `StyxNode` - Network endpoint addresses
- `StyxSpaceLink` - Distributed space connections
- `StyxRemoteLink` - Remote execution operations

**Example:**
```bash
# Mount remote atomspace
9pfuse tcp!cluster1!564 /mnt/atomspace

# Query remote concepts
cat /mnt/atomspace/types/ConceptNode/ | head -10

# Execute pattern remotely
echo "(Get (Variable \$x) (Concept \$x))" > /mnt/atomspace/queries/search
```

See [opencog/atomspace/styx/README.md](opencog/atomspace/styx/README.md) for details.

## Neuro-Symbolic Integration

The power emerges when combining both extensions:

### 1. Distributed Neural Processing
Execute tensor operations on remote GPU clusters while maintaining symbolic
control flow:

```scheme
(StyxRemoteLink
  (StyxNode "tcp://gpu-cluster:564")
  (ATenOpLink
    (Concept "train")
    (ATenNode "model")
    (ATenNode "dataset")))
```

### 2. Symbolic Control of Neural Networks
Use pattern matching and logical inference to control neural architectures:

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
Extract symbolic rules from trained neural models:

```scheme
(FilterLink
  (Lambda (Variable "$rule")
    (GreaterThan
      (ATenOpLink (Concept "confidence") (Variable "$rule"))
      (Number 0.9)))
  (ATenOpLink (Concept "extract_rules") (ATenNode "trained_model")))
```

### 4. Federated Learning
Share learned embeddings across distributed systems:

```bash
# Sync tensor data between nodes
9pfuse tcp!node1!564 /mnt/node1
9pfuse tcp!node2!564 /mnt/node2
cp /mnt/node1/atoms/*/values/tensor /mnt/node2/atoms/*/values/tensor
```

## Getting Started

### Building

```bash
mkdir build && cd build
cmake ..
make -j
sudo make install
```

### Python Example

```python
from opencog.atomspace import AtomSpace, types
from opencog.type_constructors import *

atomspace = AtomSpace()
set_default_atomspace(atomspace)

# Create tensor atoms
weights = ATenNode("layer1_weights")
input_data = ATenNode("embeddings")

# Create tensor operation
computation = ATenOpLink(
    ConceptNode("matmul"),
    weights,
    input_data)

# Create distributed endpoint
remote = StyxNode("tcp://cluster:564")

# Execute remotely
remote_exec = StyxRemoteLink(remote, computation)
```

See [examples/atenstyx/](examples/atenstyx/) for complete examples.

## Documentation

### Core Documentation
- [Neuro-Symbolic Fabric Architecture](doc/neuro-symbolic.md)
- [ATen Atom Extensions](opencog/atoms/aten/README.md)
- [Styx Space Extensions](opencog/atomspace/styx/README.md)
- [Examples](examples/atenstyx/README.md)

### AtomSpace Foundation
- [Main README](README.md) - Core AtomSpace documentation
- [Design Notes A-D](Design-Notes-A.md) - Design philosophy
- [OpenCog Wiki](https://wiki.opencog.org/) - Community documentation

## Architecture

The ATenStyx framework adds two orthogonal extensions to the AtomSpace:

1. **Vertical Extension (ATen)**: Adds computational depth by integrating
   tensor operations directly into the atom model, enabling gradient-based
   learning over symbolic structures.

2. **Horizontal Extension (Styx)**: Adds distributional breadth by exposing
   the AtomSpace through the 9P protocol, enabling network-transparent
   access and federated reasoning.

Together, they create a **cognitive fabric** where:
- Neural networks can be represented symbolically
- Symbolic queries can invoke neural computations
- Local and remote operations are unified
- Gradient and logical inference coexist

## Implementation Status

### Completed ✓
- [x] ATen atom type definitions (ATenNode, ATenTensorLink, ATenOpLink)
- [x] Styx atom type definitions (StyxNode, StyxSpaceLink, StyxRemoteLink)
- [x] C++ class implementations for all new types
- [x] Build system integration
- [x] Comprehensive documentation
- [x] Example applications
- [x] Unit test framework

### Future Work
- [ ] Full ATen tensor integration (requires PyTorch/ATen libraries)
- [ ] Complete Styx/9P protocol implementation (requires plan9port)
- [ ] TensorValue type for efficient tensor storage
- [ ] StyxConnectionValue for connection management
- [ ] Python bindings for new atom types
- [ ] Performance benchmarks
- [ ] Real-world neuro-symbolic applications

## Contributing

This framework provides the foundation for next-generation neuro-symbolic AI.
Contributions welcome in:

- Tensor operation implementations
- Styx protocol handlers
- Example applications
- Performance optimizations
- Integration with existing neural frameworks

## References

- [ATen (A Tensor Library)](https://github.com/zdevito/ATen)
- [Plan 9 from User Space](https://9p.io/plan9/)
- [OpenCog AtomSpace](https://github.com/opencog/atomspace)
- [PyTorch](https://pytorch.org/)

## License

AGPL-3.0-or-later (consistent with OpenCog AtomSpace)

---

**ATenStyx** - Synthesizing neural computation (ATen atoms) with distributed
knowledge (Styx space) to create a neuro-symbolic cognitive fabric.
