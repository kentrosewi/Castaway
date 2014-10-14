#include "Raft.h"

/*
	Default constructor for Raft.
	@param raftName name of raft
	@param raftDescription the description of the raft
	@param raftMoveable if the raft if moveable
*/
Raft::Raft(string raftName, string raftDescription, bool raftMoveable) : Item(raftName, raftDescription, raftMoveable)
{
}

