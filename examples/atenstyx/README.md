# ATenStyx Examples

This directory contains examples demonstrating the ATenStyx neuro-symbolic cognitive fabric.

## Examples

### neuro_symbolic_demo.py

A comprehensive demonstration of the ATenStyx framework showing:
- Creation of ATen tensor nodes for neural network representation
- Building symbolic knowledge hierarchies
- Linking tensor operations to symbolic concepts
- Creating distributed Styx endpoints
- Pattern matching over hybrid neuro-symbolic structures
- Remote execution concepts

**To run:**
```bash
# After building and installing the AtomSpace with ATenStyx extensions
python3 neuro_symbolic_demo.py
```

## Framework Components

### ATen Extensions (Neural Layer)
- **ATenNode**: Named tensor references
- **ATenTensorLink**: Tensor computation graph connections
- **ATenOpLink**: Executable tensor operations

### Styx Extensions (Network Layer)
- **StyxNode**: Network protocol endpoints
- **StyxSpaceLink**: Distributed space connections
- **StyxRemoteLink**: Remote execution operations

### Integration Points
- Symbolic representation of neural architectures
- Pattern matching with neural scoring
- Distributed learning and inference
- Knowledge distillation from neural models

## Future Examples

Planned examples to demonstrate full capabilities:

1. **tensor_embeddings.py**: Store and query learned embeddings
2. **distributed_reasoning.py**: Multi-node pattern matching
3. **neural_rule_learning.py**: Extract symbolic rules from neural networks
4. **hybrid_inference.py**: Combine logical and neural inference
5. **federated_knowledge.py**: Share knowledge across Styx network

## Documentation

For more information, see:
- [ATen Extensions](../../opencog/atoms/aten/README.md)
- [Styx Extensions](../../opencog/atomspace/styx/README.md)
- [Neuro-Symbolic Fabric](../../doc/neuro-symbolic.md)
