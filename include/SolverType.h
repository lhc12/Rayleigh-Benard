#pragma once
#ifndef __SOLVERTYPE_H__
#define __SOLVERTYPE_H__

#include <iostream>
#include <cmath>
#include <cstdlib>
#include "def.h"

namespace Rayleigh_Benard{
	typedef enum{chandrasekhar_even, chandrasekhar_odd, hurle_even, hurle_odd} ModeType;
	class SolverType
	{
	public:
		SolverType(void);
		SolverType(const SolverType &_rhs);
		~SolverType(void);
		SolverType & operator=(const SolverType &_rhs);
		void solve(const ModeType &e);
		Real q0(void) const;
		Real q1(void) const;
		Real q2(void) const;
		Real A0(void) const;
		Real A1(void) const;
		Real A2(void) const;
		void a(Real _a);
		Real a(void) const;
		Real R(void) const;
		Real h(void) const;
		void h(Real _h);
		Real tol(void) const;
		void tol(Real _tol);
		friend std::ostream & operator<<(std::ostream &_os, const SolverType &_obj);
	private:
		void initialize(void);
		Real chandrasekhar_even(Real _q1, Real _q2);
		Real chandrasekhar_odd(Real _q1, Real _q2);
		Real hurle_even(Real _q1, Real _q2);
		Real hurle_odd(Real _q1, Real _q2);
		Real data_[10];
	};
	std::ostream & operator<<(std::ostream &_os, const SolverType &_obj);
}

#endif