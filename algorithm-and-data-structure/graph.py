def BFS_source(adj, source):
    """traverse the graph layer by layer
    you will have unreachable area if the graph is not fully connected

    Args:
        adj:dict(int, set(int)) -> adjacency list
        source:int -> starting node
    Returns:
        parent:dict(int, int) -> parenthood dict
        distance: dict(int, int) -> distance of every node to source
    """
    batch = [source]
    parent = {source: None}
    distance = {source: 0}

    while batch:
        new_batch = []
        for node in batch:
            # for each node in a batch
            # 1. add all it's neightbors 2. process distance 3. process parenthood
            for neighbor in adj[node]:
                if neighbor not in distance:  # don't process visited nodes
                    new_batch.append(neighbor)
                    distance[neighbor] = distance[node] + 1
                    parent[neighbor] = node
        batch = new_batch

    return {'parent': parent, 'distance': distance}


# batch is conceptually clean, you could achieve the same exploration order
# by using FIFO queue
def BFS_source_q(adj, source):
    """
    still, no escape of emission of isolated islands
    """
    q = [source]
    parent = {source: None}
    distance = {source: 0}

    while q: # process 1 node at a iteration
        node = q.pop()
        for neighbor in adj[node]:
            if neighbor not in distance:
                q = [neighbor] + q
                parent[neighbor] = node
                distance[neighbor] = distance[node] + 1

    return {'parent': parent, 'distance': distance}


def BFS(adj):
    """whole graph BFS"""
    parent_list, distance_list = [], []
    seen = []

    for node in adj:
        if node not in seen:
            island = BFS_source(adj, node)
            parent, distance = island['parent'], island['distance']
            seen.extend(parent.keys())

            parent_list.append(parent)
            distance_list.append(distance)

    return {"parent_list": parent_list,
            "distance_list": distance_list,
            "seen": seen}


def DFS_source(adj, source):
    """explore the graph depth first
    tricky points:
        1. if you provide source node, then some isolated area will not be visited
        2. this is recursive definition, and recirsive process
            you depends on every recirsive call to leave useful side effect to
            complete the whole exploration.
            If the process is interruted while it's running, there is no state
            that we could recover from
    """
    parent = {source: None}

    def visit(node):
        for neighbor in adj[node]:
            if neighbor not in parent:
                parent[neighbor] = node
                visit(neighbor)

    visit(source)
    return parent


def DFS(adj):
    """
    difference here is that I do whole graph search, even isolated islands
    """
    parent = {}

    def visit(node):
        for neighbor in adj[node]:
            if neighbor not in parent:
                parent[neighbor] = node
                visit(neighbor)

    for node in adj:
        if node not in parent:
            parent[node] = None
            visit(node)

    return parent
