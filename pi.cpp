#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <mpi.h>

	using namespace std;

	double cal_pi(int M);

int main(int argc, char *argv[]) {	

	srand(time(NULL));
	MPI_Init(&argc, &argv);

	// get world size
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	// get my rank
	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	int t1 = (double)MPI_Wtime();
	
	double global_pi;
	double my_pi;

	// root-only array
	double *data = NULL;
	if (world_rank == 0) {
		data = new double[world_size];
	} 

	int N = 1000;
	if (argc > 1) {
		N = atoi(argv[1]);
	}


	/************************************************************/
	/*                    run core function                     */
	/************************************************************/

	my_pi = cal_pi(N);


	/***************** END of core function *********************/

	// collect results
	MPI_Gather(&my_pi, 1, MPI_DOUBLE, 
		data, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);


	int t2 = (double)MPI_Wtime();
	if (world_rank == 0) {
		// calculate mean
		for (int i = 0; i < world_size; i++) {
			global_pi += data[i];
		}
		global_pi /= world_size;
		// output result
		cout << "pi = " << global_pi << endl;
		cout << "Time elasped: " << t2 - t1 << "s" << endl;
	} // end of if
	
	MPI_Finalize();
	return 0;
}

double cal_pi(int M) {
	int count = 0;
	double x, y, r, result;
	for (int i = 0; i < M; i++) {
		x = rand() / (INT_MAX * 1.0);
		y = 1.0 * rand() / (INT_MAX * 1.0);
		r = sqrt( pow(x,2) + pow(y,2) );
		if (r < 1) {
			count++;
		}
	}
	result = (count*4.0) / M;
	return result;
}
