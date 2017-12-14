/*
 * Main executable for running sampling of linear models with a provided Gaussian mean.
 * Created by Lars Gebraad on 7/11/17.
 */

#include "src/hmc/hmc.hpp"
#include <ctime>
#include <armadillo/armadillo-8.200.2/include/armadillo>
#include <omp.h>
#include <time.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {

    // Standard settings
    hmc::InversionSettings settings(argc, argv);

    // Creating the sampler
    hmc::sampler sampler1(settings);

    // Running the actual sampler
    sampler1.sample();

    return EXIT_SUCCESS;
}
