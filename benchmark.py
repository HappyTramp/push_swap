import sys
import time
import json
import random
import collections
import subprocess


def random_stack(start, end):
    st = list(range(start, end))
    random.shuffle(st)
    return st


def run_bench_size(size, samples):
    runs = []
    for _ in range(samples):
        st = random_stack(1, size + 1)
        out = subprocess.check_output([f"./push_swap", *[str(x) for x in st]])
        ops = out.decode().strip().split("\n")
        runs.append({
            "ops_num": len(ops),
            "ops_counter": dict(collections.Counter(ops)),
        })
    return runs

def run_bench(start, end, step, samples=1):
    bench = {
        "start": start,
        "end": end,
        "step": step,
        "data": []
    }
    for i in range(start, end, step):
        bench["data"].append(run_bench_size(i, samples))
    return bench

if __name__ == "__main__":
    if len(sys.argv) != 4 and len(sys.argv) != 5:
        print(f"Usage: {sys.argv[0]} start stop step [samples]")
        sys.exit(1)
    samples = int(sys.argv[4]) if len(sys.argv) == 5 else 1
    with open("benchmark.json", "w") as file:
        bench = run_bench(int(sys.argv[1]),
                          int(sys.argv[2]),
                          int(sys.argv[3]),
                          samples)
        file.write(json.dumps(bench))
