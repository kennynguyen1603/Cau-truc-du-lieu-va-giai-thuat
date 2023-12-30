class Node:
    def __init__(self, data=0, next_node=None):
        self.data = data
        self.next_node = next_node

    def get_data(self):
        return self.data

    def set_data(self, data):
        self.data = data

    def get_next(self):
        return self.next_node

    def set_next(self, next_node):
        self.next_node = next_node


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_tail(self, node):
        if not self.head:
            self.head = node
            self.tail = node
        else:
            self.tail.set_next(node)
            self.tail = node

    def insert_after(self, place, value):
        if place < 1:
            return
        if place == 1:
            self.insert_head(Node(value))
            return

        temp = self.head
        for i in range(1, place):
            if temp is None:
                return
            temp = temp.get_next()

        if temp == self.tail:
            self.insert_tail(Node(value))
        else:
            new_node = Node(value)
            new_node.set_next(temp.get_next())
            temp.set_next(new_node)

    def count_el_list(self):
        count = 0
        temp = self.head
        while temp:
            count += 1
            temp = temp.get_next()
        return count

    def traval(self):
        output = []
        temp = self.head
        while temp:
            output.append(temp.get_data())
            temp = temp.get_next()
        return output


# Emulating the main function from the C++ code
def main():
    l2 = LinkedList()
    for i in range(10):
        l2.insert_tail(Node(i))
    output1 = l2.traval()
    l2.insert_after(5, 100)
    output2 = l2.traval()
    return output1, output2

# Execute the main function and capture the output
main_output = main()
print(main_output)
