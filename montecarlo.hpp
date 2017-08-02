//
// Created by Lars Gebraad on 7/11/17.
//

#ifndef HMC_VSP_MONTECARLO_HPP
#define HMC_VSP_MONTECARLO_HPP

#include <libio.h>

class montecarlo {
public:
    // Constructors and destructors
    montecarlo(prior &in_prior, data &in_data, posterior &in_posterior, forwardModel
    in_model, int in_nt, double in_dt, int in_iterations);


    ~montecarlo();

    // Fields
    prior _prior;
    data _data;
    forwardModel _model;
    posterior _posterior;
    int _nt; // Number of time steps for trajectory
    double _dt; // Time step for trajectory
    int _iterations; // Number of iterations for Monte Carlo sampling

    std::vector<double> _currentModel;
    std::vector<double> _proposedModel;
    std::vector<double> _currentMomentum;
    std::vector<double> _proposedMomentum;

    std::vector<std::vector<double>> _massMatrix;
    // Member functions

    void propose_metropolis();

    void propose_hamilton(int &uturns);

    void leap_frog(_IO_FILE *trajectoryfile, int &uturns);

    double chi();

    double energy();

    void sample(bool hamilton);

    void write_sample(_IO_FILE *pfile, double misfit, int iteration);

    void write_trajectory(_IO_FILE *pfile, int iteration);
};

#endif //HMC_VSP_MONTECARLO_HPP
