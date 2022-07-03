import re
import time

#with open('ClarissaHarlowe.txt', encoding='ascii') as f:
with open('ClarissaHarlowe.txt', encoding='ascii') as f:
    text = f.read()
t0 = time.perf_counter()
d = {}

for word in re.split('[^a-xzA-Z]+', text):
    if len(word) > 3:
        d[word] = d.get(word, 0) + 1
max_word = max(d.items(), key=lambda x: x[1])
print(f'Most frequent: "{max_word[0]}", count: {max_word[1]}')
print(f'Elapsed: {time.perf_counter() - t0}')
