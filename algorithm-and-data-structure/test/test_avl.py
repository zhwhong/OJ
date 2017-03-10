from avl import AVL
import random


def test_tree_construction():
    for _ in range(100):
        n = random.randint(0, 100)
        tree = AVL(range(n))

        assert tree.check_ri()
