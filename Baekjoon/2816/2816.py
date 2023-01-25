N = int(input())
channels = []
cursor = 0
for i in range(N):
	channels.append(input())
target_list = ['KBS1', 'KBS2']
for t in target_list:
	kbs_index = channels.index(t)
	for i in range(kbs_index):
		print("3", end="")
		cursor += 1
	tmp = channels[kbs_index - 1]
	channels[kbs_index - 1] = channels[kbs_index]
	channels[kbs_index] = tmp
	kbs_index -= 1
	if (kbs_index != 0):
		print("2", end="")
		cursor -= 1
		for i in range(kbs_index):
			print("4", end="")
			cursor -= 1
	channels.remove(t)
