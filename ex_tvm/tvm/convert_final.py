from os import dup
from sys import displayhook
import pygraphviz as pgv
import re

A = pgv.AGraph(directed=True)

# path = "./digraph.txt"
# path = "./graph_fuse_before.txt"
# path = "/home/j/tvm-tuned/tvm_test/graph_tool/before_final.txt"
# path = "/home/j/tvm-tuned/tvm_test/graph_tool/after_final.txt"
# name = "after_mod_astext"
name = "before_mod_astext"
f = open(name + ".txt", "r")

digraph = dict()

line_type_re = re.compile("\s*%[a-zA-Z0-9_-]+ = ")
getnum_re = re.compile("\d+")
getreg_re = re.compile("%[a-zA-Z0-9_-]+")
getvar_re = re.compile("[a-zA-Z0-9_.-]+")

node_re = re.compile("node\[\d+\]")
output_re = re.compile("outputs=\[[\d, ]+\]")
tensor_re = re.compile("TensorType\([^)]+\)")
brace_re = re.compile("\([^)]+\)")
while True:
    line = f.readline()
    line = line.replace("\n", "")
    if not line: 
        break
    line_info = line_type_re.findall(line)
    if len(line_info) == 0:
        continue
    # line_info = line_info[0]
    dst_info = line.split("=")[0]
    src_info = line.split('=')[1]

    dst_node = getvar_re.findall(dst_info)[0]

    op_node = getvar_re.findall(src_info.split("(")[0])[0]

    src_nodes = [getvar_re.findall(reg)[0] for reg in getreg_re.findall(src_info)]

    # for src in srcs_nodes

    digraph[dst_node] = {"name" : op_node + "_" + dst_node, "srcs" : src_nodes}

    # node_num = getnum_re.findall(str(node_re.findall(line)))[0]
    # # print("node ", node_num)
    # ll = line.split(", ")
    # kk = len(ll[1].split('(')[0])

    # # print("op : ", ll[1][kk+1:])
    # name = node_num + " : " + ll[1][kk+1:]
    # if ll[1][:kk] == "Var":
    #     # print("tensor : ",tensor_re.findall(line)[0])
    #     name +=  brace_re.findall(str(tensor_re.findall(line)[0]))[0]
    # dsts = getnum_re.findall(str(output_re.findall(line)))
    # digraph[node_num] = {"name" : name, "dsts" : dsts}
    # # print(getnum_re.findall(str(output_re.findall(line))))

    # # print(line)



print(digraph)
# # d = {"1": {"2": "set"}, "2": {"1": None, "3": None}, "3": {"2": None}}
A = pgv.AGraph(directed=True)
for node in digraph:
    dst = digraph[node]['name']
    srcs = digraph[node]['srcs']
    A.add_node(dst, shape='box')
    for src in srcs:
        try:
            A.add_edge(digraph[src]['name'], dst)
        except:
            A.add_edge(src, dst)
# # A.draw("graph_before.png", prog='dot')
A.draw(name + ".png", prog='dot')

# import re

# single_value = pp.QuotedString(quoteChar="(", endQuoteChar=")")
# parser = pp.nestedExpr(opener="[", closer="]",
#                        content=single_value,
#                        ignoreExpr=None)

# txt = "(node[13216], CallNode(Op(nn.max_pool2d), [CallNode(Op(nn.relu), [CallNode(Op(nn.bias_add), [CallNode(Op(nn.conv2d), [Var(input_1, ty=TensorType([1, 3, 28, 28], float32)), Var(_param_1, ty=TensorType([32, 3, 3, 3], float32))], relay.attrs.Conv2DAttrs(0x556fd86923f8), [TensorType([1, 3, 28, 28], float32), TensorType([32, 3, 3, 3], float32)]), Var(_param_2, ty=TensorType([32], float32))], relay.attrs.BiasAddAttrs(0x556fd86eaf78), [TensorType([1, 32, 26, 26], float32), TensorType([32], float32)])], (nullptr), [TensorType([1, 32, 26, 26], float32)])], relay.attrs.MaxPool2DAttrs(0x556fd86ec258), [TensorType([1, 32, 26, 26], float32)]), outputs=[1, 2,3,4])"
# txt = "node[2], Var(_param_2, ty=TensorType([32], float32)) outputs=[4, ]"
# node_re = re.compile("node\[\d+\]")
# output_re = re.compile("outputs=\[[\d, ]+\]")
# getnum_re = re.compile("\d+")
# # node_re = re.compile("outputs=\[[\d, ]+\]")
# print(getnum_re.findall(str(node_re.findall(txt)[0])))
# ll = txt.split(", ")
# kk = len(ll[1].split('(')[0])
# print(ll[1][kk+1:])
# print(getnum_re.findall(str(output_re.findall(txt)[0])))

# # example = "(<some value with spaces and m$1124any crazy signs> (<more values>) <even more>)"
# # print(parser.parseString(txt, parseAll=True))


# # txt = "node[13216], CallNode(Op(nn.max_pool2d), [CallNode(Op(nn.relu), [CallNode(Op(nn.bias_add), [CallNode(Op(nn.conv2d), [Var(input_1, ty=TensorType([1, 3, 28, 28], float32)), Var(_param_1, ty=TensorType([32, 3, 3, 3], float32))], relay.attrs.Conv2DAttrs(0x556fd86923f8), [TensorType([1, 3, 28, 28], float32), TensorType([32, 3, 3, 3], float32)]), Var(_param_2, ty=TensorType([32], float32))], relay.attrs.BiasAddAttrs(0x556fd86eaf78), [TensorType([1, 32, 26, 26], float32), TensorType([32], float32)])], (nullptr), [TensorType([1, 32, 26, 26], float32)])], relay.attrs.MaxPool2DAttrs(0x556fd86ec258), [TensorType([1, 32, 26, 26], float32)]), outputs=[]"
# # txt = "node[1], Var(_param_1, ty=TensorType([32, 3, 3, 3], float32)) outputs=[3, ]"
# # ll = txt.split(", ")
# # kk = len(ll[1].split('(')[0])
# # print(ll[0], ll[1][kk+1:], ll[-1])

