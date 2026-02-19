# Styx Space Extensions

This module extends the AtomSpace with Plan 9 Styx protocol integration,
enabling distributed access to the knowledge representation system.

## Overview

Styx is the 9P protocol from Plan 9, a network protocol for accessing
hierarchical file systems. This extension treats the AtomSpace as a
distributed file system, where:

- **Atoms are files**: Each atom is accessible as a synthetic file
- **Spaces are directories**: AtomSpace hierarchies map to directory structures
- **Operations are I/O**: Read/write operations trigger atom queries and updates
- **Network transparent**: Remote systems access atoms through standard 9P clients

## Architecture

The Styx extension implements a 9P file server that exposes the AtomSpace:

```
/atomspace/
  /atoms/          - All atoms by UUID
    /<uuid>/       - Individual atom directory
      /type        - Atom type name
      /name        - Node name (for nodes)
      /outgoing    - Outgoing set (for links)
      /incoming    - Incoming set
      /values/     - Attached values
  /types/          - Atoms organized by type
    /ConceptNode/
    /ATenNode/
    /...
  /queries/        - Pattern matching queries
  /execute/        - Execute atoms
```

## Atom Types

### StyxNode
Represents a Styx protocol endpoint or connection.

```scheme
(StyxNode "tcp://server:564")  ; Styx server endpoint
```

### StyxSpaceLink
Links representing distributed AtomSpace connections.

```scheme
(StyxSpaceLink
  (StyxNode "remote://cluster1")
  (ConceptNode "distributed_knowledge"))
```

## Values

### StyxConnectionValue
A Value type that maintains active Styx protocol connections.

## Integration with Distributed Systems

The Styx extension enables:
1. **Distributed reasoning**: Query atoms across network clusters
2. **Federated learning**: Share knowledge between multiple AtomSpaces
3. **Remote execution**: Execute atoms on remote systems
4. **Transparent access**: Use standard 9P tools (9P mount, cat, echo)

## Usage Example

### Python API
```python
from opencog.atomspace import AtomSpace, types
from opencog.atomspace.styx import StyxServer

atomspace = AtomSpace()

# Start Styx server
server = StyxServer(atomspace, port=564)
server.start()

# Create distributed connection
remote_node = atomspace.add_node(types.StyxNode, "tcp://remote:564")
```

### Command Line (9P client)
```bash
# Mount AtomSpace via Styx/9P
9pfuse tcp!localhost!564 /mnt/atomspace

# Browse atoms
ls /mnt/atomspace/types/ConceptNode/

# Read atom
cat /mnt/atomspace/atoms/12345/type

# Query atoms
echo "(Concept 'AI')" > /mnt/atomspace/queries/search
cat /mnt/atomspace/queries/search
```

## Protocol Details

The Styx/9P protocol provides:
- **Qid-based addressing**: Each atom has unique qid for caching
- **Versioning**: Track atom modifications through qid.version
- **Walking**: Navigate atom graph through path traversal
- **Streaming**: Large value sets stream efficiently

## Building

The Styx extension requires Plan 9 from User Space (plan9port) libraries:
```bash
sudo apt-get install plan9port  # Debian/Ubuntu
```

## See Also

- [AtomSpace Documentation](../README.md)
- [ATen Atom Extensions](../atoms/aten/README.md)
- [Plan 9 Documentation](https://9p.io/plan9/)
- [Neuro-Symbolic Fabric](../../doc/neuro-symbolic.md)
