def in_order(root):
    """recursively left - mid - right"""
    if root is None:
        return []
    else:
        return in_order(root.left) + [root.key] + in_order(root.right)


def pre_order(root):
    """recursively mid - left - right"""
    if root is None:
        return []
    else:
        return [root.key] + pre_order(root.left) + pre_order(root.right)


def post_order(root):
    """recursively left - right - mid"""
    if root is None:
        return []
    else:
        return post_order(root.left) + post_order(root.right) + [root.key]


def BFS(root):
    """traverse the tree layer by layer"""
    if root is None:
        return []
    else:
        batch = [root]
        res = []
        while batch:
            new_batch = []
            for node in batch:
                res.append(node.key)
                if node.left:
                    new_batch.append(node.left)
                if node.right:
                    new_batch.append(node.right)

            batch = new_batch
        return res
