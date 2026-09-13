#include <stdio.h>
#include <stdlib.h>

static int egg_drop_trials(int eggs, int floors)
{
	int *dp = malloc((size_t)(eggs + 1) * (floors + 1) * sizeof(*dp));
	if (dp == NULL) {
		return -1;
	}

#define DP(e, f) dp[(size_t)(e) * (floors + 1) + (f)]

	for (int e = 0; e <= eggs; ++e) {
		DP(e, 0) = 0;
		if (floors >= 1) {
			DP(e, 1) = 1;
		}
	}

	for (int f = 0; f <= floors; ++f) {
		DP(1, f) = f;
	}

	for (int e = 2; e <= eggs; ++e) {
		for (int f = 2; f <= floors; ++f) {
			DP(e, f) = floors + 1;
			for (int x = 1; x <= f; ++x) {
				int broken = DP(e - 1, x - 1);
				int survives = DP(e, f - x);
				int worst_case = 1 + (broken > survives ? broken : survives);
				if (worst_case < DP(e, f)) {
					DP(e, f) = worst_case;
				}
			}
		}
	}

	int answer = DP(eggs, floors);
	free(dp);
#undef DP
	return answer;
}

int main(void)
{
	int eggs;
	int floors;

	printf("Enter number of eggs and floors: ");
	if (scanf("%d %d", &eggs, &floors) != 2 || eggs < 1 || floors < 0) {
		fprintf(stderr, "Invalid input. Use E >= 1 and F >= 0.\n");
		return EXIT_FAILURE;
	}

	int result = egg_drop_trials(eggs, floors);
	if (result < 0) {
		fprintf(stderr, "Unable to allocate the DP table.\n");
		return EXIT_FAILURE;
	}

	printf("Minimum guaranteed droppings: %d\n", result);
	printf("Time complexity: O(E * F^2)\n");
	printf("Space complexity: O(E * F)\n");
	return EXIT_SUCCESS;

}
