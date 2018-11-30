#include "StochasticDifferentialEquation.hpp"
#include <iostream>

using namespace std;
namespace MC {

	StochasticDifferentialEquation::StochasticDifferentialEquation(double initial_value) :
		initial_value_(initial_value)
	{}

	StochasticDifferentialEquation::StochasticDifferentialEquation(const StochasticDifferentialEquation& sde) :
		initial_value_(sde.initial_value_)
	{}

	StochasticDifferentialEquation& StochasticDifferentialEquation::operator=(
		const StochasticDifferentialEquation& sde)
	{
		if (initial_value_ != sde.initial_value_)
			initial_value_ = sde.initial_value_;
		return *this;
	}


	///////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////    Black Scholes SDE      ////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	StochasticDifferentialEquationBlackScholes::StochasticDifferentialEquationBlackScholes(
		double initial_value,
		double drift,
		double volatility
	) :
		StochasticDifferentialEquation(initial_value), drift_(drift), volatility_(volatility)
	{}

	StochasticDifferentialEquationBlackScholes::StochasticDifferentialEquationBlackScholes(
		const StochasticDifferentialEquationBlackScholes& sde) :
		StochasticDifferentialEquation(sde), drift_(sde.drift_), volatility_(sde.volatility_)
	{}

	double StochasticDifferentialEquationBlackScholes::drift_function(double time, double asset_price) const
	{
		return drift_ * asset_price;
	}

	double StochasticDifferentialEquationBlackScholes::volatility_function(double time, double asset_price) const
	{
		return volatility_ * asset_price;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////    CIR SDE      ////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	StochasticDifferentialEquationCoxIngersollRoss::StochasticDifferentialEquationCoxIngersollRoss(
		double initial_value,
		double mean_reversion_speed,
		double long_term_mean,
		double volatility
	) :
		StochasticDifferentialEquation(initial_value),
		mean_reversion_speed_(mean_reversion_speed),
		long_term_mean_(long_term_mean),
		volatility_(volatility)
	{}

	StochasticDifferentialEquationCoxIngersollRoss::StochasticDifferentialEquationCoxIngersollRoss(
		const StochasticDifferentialEquationCoxIngersollRoss& sde) :
		StochasticDifferentialEquation(sde),
		mean_reversion_speed_(sde.mean_reversion_speed_),
		long_term_mean_(sde.long_term_mean_),
		volatility_(sde.volatility_)
	{}

	double StochasticDifferentialEquationCoxIngersollRoss::drift_function(double time, double asset_price) const
	{
		return mean_reversion_speed_ * (long_term_mean_ - asset_price);
	}

	double StochasticDifferentialEquationCoxIngersollRoss::volatility_function(double time, double asset_price) const
	{
		return volatility_ * std::sqrt(asset_price);
	}
} //namespace MC
