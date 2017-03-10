class BSTNode(object):
    def __init__(self, key, parent):
        self.key = key
        self.parent = parent
        self.left = None
        self.right = None

    def __repr__(self):
        return self.__str__()

    def insert(self, node):  # should I insert a node or insert a key?
        if node is None:
            return

        if node.key < self.key:
            if self.left is None:
                node.parent = self
                self.left = node
            else:
                self.left.insert(node)
        else:
            if self.right is None:
                node.parent = self
                self.right = node
            else:
                self.right.insert(node)

    def find(self, k):  # recursive version
        if k == self.key:
            return self
        elif k < self.key and self.left is not None:
            return self.left.find(k)
        elif k >= self.key and self.right is not None:
            return self.right.find(k)
        else:
            return None  # couldn't find it

    def find_iter(self, k):
        crawler = self

        while crawler is not None:
            if k == crawler.key:
                return crawler
            elif k < crawler.key:
                crawler = crawler.left
            else:
                crawler = crawler.right

        return None  # couldn't find it

    def find_max(self):
        if self.right is None:
            return self
        else:
            return self.right.find_max()

    def find_max_iter(self):
        crawler = self

        while crawler.right is not None:
            crawler = crawler.right

        return crawler

    def find_min(self):
        if self.left is None:
            return self
        else:
            return self.left.find_min()

    def find_next_larger(node):  # refer to cc150 4-6
        if node.right:
            return node.right.find_min()  # you find the right tree's min
        else:
            current, parent = node, node.parent
            while parent and parent.right is current:
                current, parent = parent, parent.parent  # keep escalating up

            return parent  # you either got a None parent, or you find one, either one is valid answer

    def find_next_larger_recur(self):
        if self.right is not None:
            return self.right.find_min()
        else:
            if self.parent is not None:
                if self.parent.left is self:
                    return self.parent
                else:
                    return self.parent.find_next_larger_recur()
            else:  # parent is None, dead end. Stop here
                return None

    def find_next_smaller(self):  # perfect symmetry, change right to left, you got it.
        pass

    def delete(self):
        """
        Order this node to be detached from the tree.
        The tricky part is you don't considert if "self" happend to be root of
        the tree situation.Because this situation will be tackled in Tree class's
        delete method by using a pseudo root.

        3 cases:
          1. I have no child
          2. I have 1 child
          3. I have 2 child
        """

        if self.left is None or self.right is None:  # handle case 1 & 2
            if self is self.parent.left:  # need 2 case, I am my parent's left or right children
                self.parent.left = self.left or self.right  # attach my children to my parent. I may have one or not
                if self.parent.left is not None:  # if I do have one, now my parent recognize as his children
                    self.parent.left.parent = self.parent  # change the child's parent from me to my parent
            else:  # symmetric
                self.parent.right = self.left or self.right
                if self.parent.right is not None:
                    self.parent.right.parent = self.parent
        else:  # case 3
            """
            have two children, guaranteed to have next larger, actually,
            we could choose next smaller to replace myself. Same effect.
            """
            next_larger_node = self.find_next_larger()

            next_larger_node.key, self.key = self.key, next_larger_node.key  # swap keys

            return next_larger_node.delete()

    def check_ri(self):
        """
        we check 2 things:
          1. key order
          2. pointers are connected right
        """

        if self.left is not None:
            if self.left.key > self.key:
                raise RuntimeError("RI violiated by left node's key")

            if self.left.parent is not self:
                raise RuntimeError("RI violiated by left node parent pointer")

            self.left.check_ri()

        if self.right is not None:
            if self.right.key < self.key:
                raise RuntimeError("RI violiated by right node's key")

            if self.right.parent is not self:
                raise RuntimeError("RI violiated by right node parent pointer")

            self.right.check_ri()

        return True

    def _str(self):
        """Internal method for ASCII art.Copied from MIT code, I didn't write it XD"""
        label = str(self.key)

        if self.left is None:
            left_lines, left_pos, left_width = [], 0, 0
        else:
            left_lines, left_pos, left_width = self.left._str()

        if self.right is None:
            right_lines, right_pos, right_width = [], 0, 0
        else:
            right_lines, right_pos, right_width = self.right._str()

        middle = max(right_pos + left_width - left_pos + 1, len(label), 2)
        pos = left_pos + middle // 2
        width = left_pos + middle + right_width - right_pos

        while len(left_lines) < len(right_lines):
            left_lines.append(' ' * left_width)

        while len(right_lines) < len(left_lines):
            right_lines.append(' ' * right_width)

        if (middle - len(label)) % 2 == 1 and self.parent is not None and \
           self is self.parent.left and len(label) < middle:
            label += '.'

        label = label.center(middle, '.')

        if label[0] == '.':
            label = ' ' + label[1:]
        if label[-1] == '.':
            label = label[:-1] + ' '

        lines = [' ' * left_pos + label + ' ' * (right_width - right_pos),
                 ' ' * left_pos + '/' + ' ' * (middle - 2) +
                 '\\' + ' ' * (right_width - right_pos)] + \
          [left_line + ' ' * (width - left_width - right_width) + right_line
           for left_line, right_line in zip(left_lines, right_lines)]

        return lines, pos, width

    def __str__(self):
        return '\n'.join(self._str()[0])


class BST(object):
    def __init__(self, array=[]):
        self.root = None
        if array:
            for k in array:
                self.insert(k)

    def __str__(self):
        if self.root is None:
            return '<empty tree>'
        return str(self.root)

    def __repr__(self):
        return self.__str__()

    def insert(self, key):
        """
        the reason why we need to return the inserted node and deleted node
        is we need it when doing AVL
        """
        new_node = BSTNode(key, None)

        if self.root is None: # take care of root case. Don't care when implementing BSTNode, because only tree have root
            self.root = new_node
        else:
            self.root.insert(new_node)

        return new_node

    def find(self, k):
        return self.root and self.root.find(k) # .... find bug here, should be and

    def find_min(self):
        return self.root and self.root.find_min()

    def find_max(self):
        return self.root and self.root.find_max()

    def find_next_larger(self, k):
        node = self.find(k)

        if node:
            return node.find_next_larger()

    def delete(self, k):
        """
        to delete a node with key = k
        """
        node = self.root.find(k)  # first you need to find it

        if node is None:  # don't find, whatever
            return None

        if node is self.root:  # take care of root case
            pseudo_root = BSTNode(0, None)  # create a fake root

            pseudo_root.left = self.root  # mutually link fake root and real root
            self.root.parent = pseudo_root

            delete_node = self.root.delete()  # delete what you want to delete

            self.root = pseudo_root.left  # restore the tree's root.

            if self.root is not None:  # if the self.root still exist, remove it's fake parent link
                self.root.parent = None

            return delete_node

        else:  # if the node is not a root, easy, just delete it
            return node.delete()

    def check_ri(self):
        if self.root is None:
            return True
        elif self.root.parent is not None:
            print("BST RI violated by the root's parent's pointer")
            return False
        else:
            return self.root.check_ri()


def height(node):
    if node is None:
        return -1 # define as -1 so you don't have to do cas anaysis on whether your children exist or not
    else:
        return node.height


def update_height(node):
    node.height = max(height(node.left), height(node.right)) + 1


class AVL(BST):
    def left_rotate(self, x):
        """
        ok, here is the tricky part, how would you know y will exist. The answer is no. But the situation you will
        call left_rotate is when x is right heavy. So it contradicts when x is right heavy while x.right is None.
        If you use left_rotate strickly in this situation, it won't be a problem.

        That is to say, you can't left_rotate any tree at your will. The context is important!

        3 links to be reconnected:
          1. y--parent
          2. x--beta
          3. x--y

        need to be done in this order. if you do 3 first, original y--beta link will lost so you cant connect x--beta
        """
        y = x.right # init y

        y.parent = x.parent # take care first link: y--parent
        if y.parent is None: # just take care of root situtaion
            self.root = y
        else: # not a root, case analysis
            if y.parent.left is x:
                y.parent.left = y
            elif y.parent.right is x:
                y.parent.right = y

        x.right = y.left # take care of second link: x--beta
        if x.right is not None:
            x.right.parent = x

        y.left = x # link: x--y
        x.parent = y

        update_height(x) # don't forget to update height
        update_height(y)

    def right_rotate(self, x): # symmetric to left_rotate
        y = x.left

        y.parent = x.parent
        if y.parent is None:
            self.root = y
        else:
            if y.parent.left is x:
                y.parent.left = y
            elif y.parent.right is x:
                y.parent.right = y

        x.left = y.right
        if x.left is not None:
            x.left.parent = x

        y.right = x
        x.parent = y

        update_height(x)
        update_height(y)

    def rebalance(self, x):
        """
        1. it's all about case analysis, take advantage of symmetric nature of tree operation.

        2. We need to rebalance all the way up to the root.
        """
        while x is not None:
            update_height(x)

            if height(x.right) >= height(x.left) + 2: # first, assume x is right heavy
                if height(x.right.right) >= height(x.right.left): # and x child is right heavy too, which means x is super right heavy here
                    self.left_rotate(x) # this case, 1 left rotate on x would do it
                else: # when x is right heavy, but the right child is left heavy...
                    self.right_rotate(x.right) # right rotate for the child first
                    self.left_rotate(x) # left rotate to balance x
            elif height(x.left) >= height(x.right) + 2: # symmetric
                if height(x.left.left) >= height(x.left.right):
                    self.right_rotate(x.left)
                else:
                    self.left_rotate(x.left)
                    self.right_rotate(x)

            x = x.parent # balance all the way up

    def insert(self, k):
        new_node = super().insert(k) # this is python3 specific, the usage of super() is different in python2

        self.rebalance(new_node)
        # reason to rebalance this node is just to init the height for new node, otherwise we could just reba its parent

    def delete(self, k):
        del_node = super().delete(k)

        self.rebalance(del_node.parent) # this is the first possible out of balance node.
