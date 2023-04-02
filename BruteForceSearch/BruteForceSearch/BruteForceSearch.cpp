#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <random>

using namespace std;

//int random(int end) {
//	random_device rd;
//	default_random_engine eng{ rd() };
//	uniform_int_distribution<> dist(0, end);
//	return dist(eng);
//}

int random(int max) {
	static unsigned int seed = 0;
	if (seed == 0) {
		seed = (unsigned int)time(NULL);
	}
	seed = (1103515245 * seed + 12345) % (1 << 31);
	return (int)(seed % (max + 1));
}

int binomialCoefficients(int n, int k) {
	if (k == 0 || k == n) {
		return 1;
	}
	return binomialCoefficients(n - 1, k - 1) + binomialCoefficients(n - 1, k);
}

//int** comb(int N, int K) {
//	int size = binomialCoefficients(N, K);
//	int i = 0, j = 0, l;
//	int** combinations = new int* [size];
//	string bitmask(K, 1);
//	bitmask.resize(N, 0);
//
//	do {
//		combinations[i] = new int[K];
//		for (l = 0; l < N; ++l)
//		{
//			if (bitmask[l]) {
//				combinations[i][j] = l;
//				j++;
//			}
//		}
//		i++;
//	} while (prev_permutation(bitmask.begin(), bitmask.end()));
//	return combinations;
//}

////int** createArray(int m, int n) {
////	float* values = calloc(m * n, sizeof(float));
////	float** rows = malloc(m * sizeof(float*));
////	for (int i = 0; i < m; ++i)
////	{
////		rows[i] = values + i * n;
////	}
////	return rows;

void destroyArray(float** arr) {
	free(*arr);
	free(arr);
}

void printArray(int* arr, int m) {
	for (int i = 0; i < m; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void printArray(int** arr, int m, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void printArray(char** arr, int m, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int** buildFourCombinations(int lotteryNumbers) {
	int a, b, c, d, count = 0;
	int** combinations = new int* [17550];
	for (a = 0; a < lotteryNumbers - 3; a++) {
		for (b = a + 1; b < lotteryNumbers - 2; b++) {
			for (c = b + 1; c < lotteryNumbers - 1; c++) {
				for (d = c + 1; d < lotteryNumbers; d++) {
					combinations[count] = new int[4];
					combinations[count][0] = a;
					combinations[count][1] = b;
					combinations[count][2] = c;
					combinations[count][3] = d;
					count++;
				}
			}
		}
	}
	return combinations;
}

int** buildSixCombinations(int lotteryNumbers) {
	int a, b, c, d, e, f, count = 0;
	int** combinations = new int* [296010];
	for (a = 0; a < lotteryNumbers - 5; a++) {
		for (b = a + 1; b < lotteryNumbers - 4; b++) {
			for (c = b + 1; c < lotteryNumbers - 3; c++) {
				for (d = c + 1; d < lotteryNumbers - 2; d++) {
					for (e = d + 1; e < lotteryNumbers - 1; e++) {
						for (f = e + 1; f < lotteryNumbers; f++) {
							combinations[count] = new int[6];
							combinations[count][0] = a;
							combinations[count][1] = b;
							combinations[count][2] = c;
							combinations[count][3] = d;
							combinations[count][4] = e;
							combinations[count][5] = f;
							count++;
						}
					}
				}
			}
		}
	}
	return combinations;
}

int intersection(int set1[], int set2[], int set1Size, int set2Size) {
	int i, j;
	int intersectionSize = 0;
	for (i = 0; i < set1Size; i++) {
		for (j = 0; j < set2Size; j++) {
			if (set1[i] == set2[j]) {
				intersectionSize++;
				break;
			}
		}
	}
	return intersectionSize;
}

void shuffle(int* array, size_t n) {
	if (n > 1) {
		size_t i;
		for (i = 0; i < n - 1; i++) {
			size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
			int t = array[j];
			array[j] = array[i];
			array[i] = t;
		}
	}
}

void shuffle(int** arr, int rows, int cols) {
	srand(time(NULL)); // seed random number generator

	// iterate through each row in the array
	for (int i = 0; i < rows; i++) {
		// iterate through each column in the row
		for (int j = 0; j < cols; j++) {
			// generate a random index within the row
			int random_index = rand() % cols;

			// swap the current element with the random element
			int temp = arr[i][j];
			arr[i][j] = arr[i][random_index];
			arr[i][random_index] = temp;
		}
	}
}

void printToFile(int** arr, int m) {
	ofstream myfile;
	myfile.open("C:/Users/Stanislav Ilchev/Desktop/result.txt");
	for (int i = 0; i < m; ++i) {
		myfile << arr[i] << " ";
	}
	myfile << "\n";
	myfile.close();
}

void printToFile(int** arr, int m, int n) {
	ofstream myfile;
	myfile.open("C:/Users/Stanislav Ilchev/Desktop/result.txt");
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			myfile << arr[i][j] << " ";
		}
		myfile << "\n";
	}
	myfile.close();
}

int main() {
	int i, j, count = 0, index = 0, v = 27, k = 6, m = 4, t = 3, b = 300, mSetsCount = binomialCoefficients(v, m), kSetsCount = binomialCoefficients(v, k);
	int** kSets = buildSixCombinations(v);
	int** mSets = buildFourCombinations(v);
	int* wheel = new int[300];
	char** intersections1 = new char* [5850];
	char** intersections2 = new char* [5850];
	char** intersections3 = new char* [5850];
	shuffle(mSets, mSetsCount, m);
	shuffle(kSets, kSetsCount, k);
	cout << "Started intersections calculation!" << endl;
	for (i = 0; i < 5850; i++) {
		intersections1[index] = new char[296010];
		for (j = 0; j < kSetsCount; j++) {
			if (intersection(mSets[i], kSets[j], m, k) >= t) {
				intersections1[index][j] = 'T';
			}
			else {
				intersections1[index][j] = 'F';
			}
		}
		index++;
	}
	index = 0;
	for (i = 5850; i < 11700; i++) {
		intersections2[index] = new char[296010];
		for (j = 0; j < kSetsCount; j++) {
			if (intersection(mSets[i], kSets[j], m, k) >= t) {
				intersections2[index][j] = 'T';
			}
			else {
				intersections2[index][j] = 'F';
			}
		}
		index++;
	}
	index = 0;
	for (i = 11700; i < mSetsCount; i++) {
		intersections3[index] = new char[296010];
		for (j = 0; j < kSetsCount; j++) {
			if (intersection(mSets[i], kSets[j], m, k) >= t) {
				intersections3[index][j] = 'T';
			}
			else {
				intersections3[index][j] = 'F';
			}
		}
		index++;
	}
	cout << "Finished intersections calculation!" << endl;
	clock_t begin = clock();

	while (kSetsCount > 0) {
	OUTER:
		count++;
		if (count == 1000000) {
			clock_t end = clock();
			cout << (double)(end - begin) / CLOCKS_PER_SEC << endl;
			begin = clock();
			count = 0;
		}
		for (i = 0; i < b; i++) {
			wheel[i] = random(kSetsCount);
		}
		i = -1;
	INNER1:
		i++;
		for (; i < 5850; i++) {
			for (j = 0; j < b; j++) {
				if (intersections1[i][wheel[j]] == 'T') {
					goto INNER1;
				}
			}
			goto OUTER;
		}
		i = -1;
	INNER2:
		i++;
		for (; i < 5850; i++) {
			for (j = 0; j < b; j++) {
				if (intersections2[i][wheel[j]] == 'T') {
					goto INNER2;
				}
			}
			goto OUTER;
		}
		i = -1;
	INNER3:
		i++;
		for (; i < 5850; i++) {
			for (j = 0; j < b; j++) {
				if (intersections3[i][wheel[j]] == 'T') {
					goto INNER3;
				}
			}
			goto OUTER;
		}
		cout << b << endl;
		ofstream myfile;
		myfile.open("C:/Users/Stanislav Ilchev/Desktop/result.txt");
		for (i = 0; i < b; i++) {
			for (j = 0; j < k; j++) {
				cout << kSets[wheel[i]][j] << " ";
				myfile << kSets[wheel[i]][j] << " ";
			}
			cout << endl;
			myfile << "\n";
		}
		myfile.close();
		//b = b - 10;
		return 0;
	}
}