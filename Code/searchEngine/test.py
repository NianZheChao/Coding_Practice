from pygraph.classes.digraph import digraph


class PRIterator:
    __doc__ = '计算一张图中的PR值'

    def __init__(self, dg):
        self.damping_factor = 0.85
        self.max_iterations = 100
        self.min_delta = 0.00001
        self.graph = dg

    def page_rank(self):
        for node in self.graph.nodes():
            if len(self.graph.neighbors(node)) == 0:
                for node2 in self.graph.nodes():
                    digraph.add_edge(self.graph, (node, node2))
        nodes = self.graph.nodes()
        graph_size = len(nodes)

        if graph_size == 0:
            return {}
        page_rank = dict.fromkeys(nodes, 1.0 / graph_size)
        damping_value = (1.0 - self.damping_factor) / graph_size
        flag = False

        for i in range(self.max_iterations):
            change = 0
            for node in nodes:
                rank = 0
                for incident_page in self.graph.incident(node):
                    rank += self.damping_factor * (page_rank[incident_page]) / len(self.graph.neighbors(incident_page))
                    rank += damping_value
                    change += abs(page_rank[node] - rank)
                    page_rank[node] = rank
                    print("This is NO.%s iteration" % (i + 1))
                    print(page_rank)
                    if change < self.min_delta:
                        flag = True
                        break

                    if flag:
                        print("finish in %s iterations!" % node)
                    else:
                        print("finish out of 100 iterations!")

                    return page_rank


def read_data(path):
    node_list = []
    edge_list = []
    with open(path) as f:
        lines = f.readlines()
        nodes = lines[1].split(' ')
        nodes[-1] = nodes[-1].split('\n')[0]
        for node in nodes:
            node_list.append(node)

        edges = lines[3:]
        for edge in edges:
            edge = edge.split(' ')
            edge[1] = edge[1].split('\n')[0]
            edge_list.append(edge)
        return node_list, edge_list


if __name__ == '__main__':
    dg = digraph()

    path = 'D:\\2020\\学习\\2020秋\\搜索引擎\\ex08\\pagerank_four_nodes.txt'

    node_list, edge_list = read_data(path)
    print('node: ', node_list)
    print('edge: ', edge_list)
    dg.add_node(node_list)
    for edg in edge_list:
        dg.add_edge(edg)

    pr = PRIterator(dg)
    page_ranks = pr.page_rank()

    print("The final page rank is\n", page_ranks)
