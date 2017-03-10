import graph as g
import pytest


@pytest.fixture
def base_graph():
    node_input = [(1, {2, 3}), (2, {3, 4, 5}), (3, {1, 2, 5, 7, 8}), (4, {2, 5}), (5, {2, 3, 4, 6}), (6, {5}), (7, {3, 8}), (8, {3, 7}), (9, {10}), (10, {9}), (11, {12}), (12, {11, 13}), (13, {12})]
    adj = dict(node_input)
    
    return adj


def test_BFS(base_graph):
    seen = g.BFS(base_graph)['seen']
    assert set(seen) == set(base_graph.keys())


def test_DFS(base_graph):
    parent = g.DFS(base_graph)
    assert set(parent.keys()) == set(base_graph.keys())
