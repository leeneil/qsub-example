#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <climits>

#define N 100

	using namespace std;

	double cal_pi(int M);

int main(int argc, char *argv[]) {	


	// get world size
	int world_size = 1;
	// get my rank
	int world_rank = 0;

	
	double global_pi;
	double my_pi;

	// root-only array
	double *data = NULL;
	if (world_rank == 0) {
		data = new double[world_size];
	} 

	/************************************************************/
	/*                    run core function                     */
	/************************************************************/

	my_pi = cal_pi(N);


	/***************** END of core function *********************/

	// collect results
	data[0] = my_pi;


	if (world_rank == 0) {
		// calculate mean
		for (int i = 0; i < world_size; i++) {
			global_pi += data[i];
		}
		// output result
		cout << "pi = " << global_pi << endl;

	} // end of if
	
	return 0;
}

double cal_pi(int M) {
	int count = 0;
	double x, y, r, result;
	for (int i = 0; i < N; i++) {
		srand(time(NULL));
		x = rand() / (INT_MAX * 1.0);
		y = rand() / (INT_MAX * 1.0);
		r = sqrt( pow(x,2) + pow(y,2) );
		if (r < 1) {
			count++;
		}
	}
	result = count / (M * 4.0);
	return result;
}
