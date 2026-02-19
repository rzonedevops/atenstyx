#!/usr/bin/env python3
"""
ATenStyx Example: Neuro-Symbolic Pattern Matching

This example demonstrates the integration of tensor operations (ATen)
with symbolic pattern matching in the AtomSpace.

Part of the ATenStyx neuro-symbolic cognitive fabric.
"""

from opencog.atomspace import AtomSpace, types
from opencog.type_constructors import *
from opencog.bindlink import execute_atom

def main():
    """Demonstrate neuro-symbolic integration"""
    
    # Create an AtomSpace
    atomspace = AtomSpace()
    set_default_atomspace(atomspace)
    
    print("=== ATenStyx Neuro-Symbolic Cognitive Fabric ===\n")
    
    # 1. Create tensor nodes (representing neural network components)
    print("1. Creating ATen tensor nodes...")
    weights = ATenNode("layer1_weights")
    input_data = ATenNode("input_embeddings")
    print(f"   Created: {weights}")
    print(f"   Created: {input_data}\n")
    
    # 2. Create symbolic knowledge
    print("2. Creating symbolic knowledge...")
    concept_ai = ConceptNode("ArtificialIntelligence")
    concept_ml = ConceptNode("MachineLearning")
    concept_nn = ConceptNode("NeuralNetworks")
    
    # Create relationships
    InheritanceLink(concept_ml, concept_ai)
    InheritanceLink(concept_nn, concept_ml)
    print(f"   Created inheritance hierarchy")
    print(f"   {concept_nn} -> {concept_ml} -> {concept_ai}\n")
    
    # 3. Create tensor computation graph
    print("3. Creating tensor computation (symbolic representation)...")
    matmul_op = ConceptNode("matmul")
    tensor_computation = ATenOpLink(
        matmul_op,
        weights,
        input_data
    )
    print(f"   Created: {tensor_computation}\n")
    
    # 4. Connect neural and symbolic layers
    print("4. Connecting neural computation to symbolic concept...")
    # Link the neural network concept to actual tensor operations
    evaluation = EvaluationLink(
        PredicateNode("implements"),
        ListLink(
            concept_nn,
            tensor_computation
        )
    )
    print(f"   Created: {evaluation}\n")
    
    # 5. Create a Styx distributed endpoint (symbolic representation)
    print("5. Creating Styx distributed endpoint...")
    remote_endpoint = StyxNode("tcp://cluster.example.com:564")
    print(f"   Created: {remote_endpoint}\n")
    
    # 6. Create distributed space link
    print("6. Creating distributed knowledge link...")
    distributed_link = StyxSpaceLink(
        remote_endpoint,
        concept_ai
    )
    print(f"   Created: {distributed_link}\n")
    
    # 7. Pattern matching over hybrid structure
    print("7. Demonstrating pattern matching over neuro-symbolic structure...")
    var_x = VariableNode("$x")
    var_y = VariableNode("$y")
    
    # Find all concepts that implement tensor operations
    pattern = GetLink(
        VariableList(var_x, var_y),
        AndLink(
            InheritanceLink(var_x, concept_ai),
            EvaluationLink(
                PredicateNode("implements"),
                ListLink(var_x, var_y)
            )
        )
    )
    
    print(f"   Pattern: Find concepts inheriting from {concept_ai}")
    print(f"            that implement tensor operations\n")
    
    # Execute the pattern (symbolic query)
    # Note: Full execution would require complete ATen integration
    print(f"   Pattern structure created: {pattern}\n")
    
    # 8. Demonstrate remote execution concept
    print("8. Creating remote execution structure...")
    remote_query = StyxRemoteLink(
        remote_endpoint,
        pattern
    )
    print(f"   Created: {remote_query}")
    print(f"   This represents executing the pattern on remote cluster\n")
    
    # 9. Display the atomspace structure
    print("9. AtomSpace structure summary:")
    all_atoms = atomspace.get_atoms_by_type(types.Atom)
    print(f"   Total atoms created: {len(all_atoms)}")
    
    print("\n   Atom types distribution:")
    type_counts = {}
    for atom in all_atoms:
        type_name = atom.type_name
        type_counts[type_name] = type_counts.get(type_name, 0) + 1
    
    for type_name, count in sorted(type_counts.items()):
        print(f"   - {type_name}: {count}")
    
    print("\n=== ATenStyx Demonstration Complete ===")
    print("\nThis example shows the foundation for:")
    print("  • Symbolic representation of neural networks")
    print("  • Pattern matching over hybrid structures")
    print("  • Distributed knowledge representation")
    print("  • Integration of tensors and hypergraphs")
    print("\nFull tensor computation requires ATen/PyTorch integration.")
    print("Full distributed access requires Styx/9P protocol implementation.")

if __name__ == "__main__":
    main()
