import sys
import json
import statistics
import collections
import numpy as np
import matplotlib.pyplot as plt


def read_bench():
    with open("benchmark.json", "r") as file:
        bench = json.loads(file.read())
        return bench


def plot_bench_ops(b):
    r = np.arange(b["start"], b["end"], b["step"])
    nlogn = r * np.log(r)
    n_square = r ** 2

    means = []
    for runs in b["data"]:
        means.append(statistics.mean(
            [runs[i]["ops_num"] for i in range(len(runs))]
        ))

    fig, ax = plt.subplots()
    ax.set(xlabel="stack length", ylabel="op number", title="push_swap benchmark")
    ax.grid()
    ax.plot(r, means)
    ax.plot(r, nlogn, label=r"$n \log(n)$")
    ax.plot(r, n_square, label=r"$n^2$")
    ax.plot(r, r, label=r"$n$")

    ax.set_ylim([0, max(means)])
    ax.set_xlim([0, max(r)])
    plt.legend()
    plt.show()


def plot_bench_distribution(b):
    counter = collections.Counter()
    for runs in b["data"]:
        for run in runs:
            counter.update(run["ops_counter"])

    fig, ax = plt.subplots()
    ax.set(xlabel="op", ylabel="time used", title="push_swap benchmark ops distribution")
    ax.bar(counter.keys(), counter.values())
    plt.show()



if __name__ == "__main__":
    b = read_bench()
    if len(sys.argv) == 2 and sys.argv[1] == "--dist":
        plot_bench_distribution(b)
    else:
        plot_bench_ops(b)
