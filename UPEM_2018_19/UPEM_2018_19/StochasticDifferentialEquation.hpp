#pragma once
#include <iostream>

namespace MC
{
	class StochasticDifferentialEquation
	{
	public:
		// Four methods to know by heart for interviews (+ the constructor with parameters to initialize)!!
		StochasticDifferentialEquation(double initial_value);
		StochasticDifferentialEquation(const StochasticDifferentialEquation& sde);
		StochasticDifferentialEquation& operator=(const StochasticDifferentialEquation& sde);
		virtual ~StochasticDifferentialEquation() = default;

		// Move semantics since C++ 11

		virtual double drift_function(double time, double asset_price) const = 0;
		virtual double volatility_function(double time, double asset_price) const = 0;

	protected:
		// Making this class protected or private prevents us to call it from outside
		StochasticDifferentialEquation() = default;
		double initial_value_;
	};

	class StochasticDifferentialEquationBlackScholes : public StochasticDifferentialEquation
	{
	public:
		StochasticDifferentialEquationBlackScholes(double initial_value, double drift, double volatility);
		StochasticDifferentialEquationBlackScholes(const StochasticDifferentialEquationBlackScholes& sde);
		~StochasticDifferentialEquationBlackScholes() = default;

		double drift_function(double time, double asset_price) const override;
		double volatility_function(double time, double asset_price) const override;

	private:
		StochasticDifferentialEquationBlackScholes() = default;
		double drift_;
		double volatility_;
	};

	class StochasticDifferentialEquationCoxIngersollRoss : public StochasticDifferentialEquation
	{
	public:
		StochasticDifferentialEquationCoxIngersollRoss(const StochasticDifferentialEquationCoxIngersollRoss& sde);
		StochasticDifferentialEquationCoxIngersollRoss(
			double initial_value,
			double mean_reversion_speed,
			double long_term_mean,
			double volatility);

		~StochasticDifferentialEquationCoxIngersollRoss() = default;

		double drift_function(double time, double asset_price) const override;
		double volatility_function(double time, double asset_price) const override;


	private:
		StochasticDifferentialEquationCoxIngersollRoss() = default;
		double mean_reversion_speed_;
		double long_term_mean_;
		double volatility_;
	};

} //namespace MC

