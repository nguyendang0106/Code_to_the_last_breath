"""
Heuristic solver for the symmetric Traveling Salesperson Problem using a
Genetic Algorithm. The instance size can reach n = 1000, therefore the solver
focuses on producing good tours quickly instead of guaranteeing optimality.

Input format
------------
Line 1: n (1 <= n <= 1000)
Next n lines: distance matrix (space separated integers)

Output format
-------------
Line 1: n
Line 2: permutation describing the tour (1-based city ids)
"""

from __future__ import annotations

import random
import sys
import time
from typing import List


def read_input() -> tuple[int, List[List[int]]]:
	data = sys.stdin.read().strip().split()
	if not data:
		return 0, []
	it = iter(data)
	n = int(next(it))
	matrix = [[0] * n for _ in range(n)]
	for i in range(n):
		row = matrix[i]
		for j in range(n):
			row[j] = int(next(it))
	return n, matrix


def evaluate(route: List[int], matrix: List[List[int]]) -> int:
	total = matrix[route[-1]][route[0]]
	for idx in range(len(route) - 1):
		total += matrix[route[idx]][route[idx + 1]]
	return total


def nearest_neighbor(start: int, matrix: List[List[int]]) -> List[int]:
	n = len(matrix)
	if n <= 1:
		return list(range(n))
	visited = [False] * n
	route = [start]
	visited[start] = True
	for _ in range(n - 1):
		last = route[-1]
		row = matrix[last]
		best_city = -1
		best_cost = None
		for city in range(n):
			if visited[city]:
				continue
			cost = row[city]
			if best_cost is None or cost < best_cost:
				best_cost = cost
				best_city = city
		route.append(best_city)
		visited[best_city] = True
	return route


def order_crossover(parent_a: List[int], parent_b: List[int]) -> List[int]:
	size = len(parent_a)
	if size < 4:
		return parent_a.copy()
	left, right = sorted(random.sample(range(size), 2))
	child = [-1] * size
	child[left:right] = parent_a[left:right]
	segment = set(child[left:right])
	pos = right
	for gene in parent_b[right:] + parent_b[:right]:
		if gene in segment:
			continue
		child[pos % size] = gene
		pos += 1
	return child


def mutate(route: List[int]) -> None:
	size = len(route)
	if size < 2:
		return
	a, b = sorted(random.sample(range(size), 2))
	if b - a <= 2:
		route[a], route[b] = route[b], route[a]
		return
	route[a:b] = reversed(route[a:b])


def tournament_selection(population: List[dict], k: int = 3) -> dict:
	k = min(k, len(population))
	candidates = random.sample(population, k)
	return min(candidates, key=lambda ind: ind["cost"])


def build_initial_population(
	n: int,
	matrix: List[List[int]],
	population_size: int,
) -> List[dict]:
	population: List[dict] = []
	seeds = {0, n // 3 if n >= 3 else 0, (2 * n) // 3 if n >= 3 else 0}
	for start in seeds:
		if 0 <= start < n:
			route = nearest_neighbor(start, matrix)
			population.append({"route": route, "cost": evaluate(route, matrix)})
	base_route = list(range(n))
	while len(population) < population_size:
		random.shuffle(base_route)
		route = base_route.copy()
		population.append({"route": route, "cost": evaluate(route, matrix)})
	return population


def genetic_algorithm(n: int, matrix: List[List[int]]) -> List[int]:
	if n <= 1:
		return list(range(n))
	random.seed()
	population_size = max(40, min(120, max(20, n // 8)))
	population = build_initial_population(n, matrix, population_size)
	elite_size = max(2, population_size // 10)
	mutation_rate = 0.25
	tournament_size = 4 if population_size >= 4 else population_size
	max_generations = max(160, 2 * population_size)
	time_limit = 1.8 if n > 200 else 2.2
	start_time = time.time()
	generation = 0
	initial_best = min(population, key=lambda ind: ind["cost"])
	best = {
		"route": initial_best["route"].copy(),
		"cost": initial_best["cost"],
	}

	while generation < max_generations and (time.time() - start_time) < time_limit:
		population.sort(key=lambda ind: ind["cost"])
		if population[0]["cost"] < best["cost"]:
			best = {"route": population[0]["route"].copy(), "cost": population[0]["cost"]}

		new_population = [
			{"route": ind["route"].copy(), "cost": ind["cost"]}
			for ind in population[:elite_size]
		]

		while len(new_population) < population_size:
			parent1 = tournament_selection(population, tournament_size)
			parent2 = tournament_selection(population, tournament_size)
			if parent1 is parent2:
				parent2 = random.choice(population)
			child_route = order_crossover(parent1["route"], parent2["route"])
			if random.random() < mutation_rate:
				mutate(child_route)
			child_cost = evaluate(child_route, matrix)
			new_population.append({"route": child_route, "cost": child_cost})

		population = new_population
		generation += 1

		if generation % 25 == 0 and (time.time() - start_time) < time_limit:
			reinject = list(range(n))
			random.shuffle(reinject)
			population[-1] = {"route": reinject, "cost": evaluate(reinject, matrix)}

	population.sort(key=lambda ind: ind["cost"])
	if best["cost"] > population[0]["cost"]:
		best = {
			"route": population[0]["route"].copy(),
			"cost": population[0]["cost"],
		}
	return best["route"]


def main() -> None:
	n, matrix = read_input()
	if n == 0:
		return
	best_route = genetic_algorithm(n, matrix)
	print(n)
	output_route = [city + 1 for city in best_route]
	print(" ".join(map(str, output_route)))


if __name__ == "__main__":
	main()