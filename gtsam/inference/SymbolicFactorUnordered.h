/* ----------------------------------------------------------------------------

 * GTSAM Copyright 2010, Georgia Tech Research Corporation,
 * Atlanta, Georgia 30332-0415
 * All Rights Reserved
 * Authors: Frank Dellaert, et al. (see THANKS for the full author list)

 * See LICENSE for the license information

 * -------------------------------------------------------------------------- */

/**
 * @file    SymbolicFactor.h
 * @author  Richard Roberts
 * @date    Oct 17, 2010
 */

#pragma once

#include <gtsam/inference/FactorUnordered.h>
#include <gtsam/inference/Key.h>

namespace gtsam {

  // Forward declaration of SymbolicConditional
  class SymbolicConditionalUnordered;

  /**
   * SymbolicFactorUnordered serves two purposes.  It is the base class for all linear
   * factors (GaussianFactor, JacobianFactor, HessianFactor), and also functions
   * as a symbolic factor, used to do symbolic elimination by JunctionTree.
   *
   * It derives from Factor with a key type of Key, an unsigned integer.
   * \nosubgrouping
   */
  class SymbolicFactorUnordered: public FactorUnordered {

  public:

    typedef SymbolicFactorUnordered This;
    typedef FactorUnordered Base;
    typedef SymbolicConditionalUnordered ConditionalType;

    /** Overriding the shared_ptr typedef */
    typedef boost::shared_ptr<This> shared_ptr;

    /// @name Standard Interface
    /// @{

    /** Virtual destructor */
    virtual ~SymbolicFactorUnordered() {}

    /** Copy constructor */
    SymbolicFactorUnordered(const This& f) : Base(f) {}

    /** Default constructor for I/O */
    SymbolicFactorUnordered() {}

    /** Construct unary factor */
    SymbolicFactorUnordered(Key j) : Base(j) {}

    /** Construct binary factor */
    SymbolicFactorUnordered(Key j1, Key j2) : Base(j1, j2) {}

    /** Construct ternary factor */
    SymbolicFactorUnordered(Key j1, Key j2, Key j3) : Base(j1, j2, j3) {}

    /** Construct 4-way factor */
    SymbolicFactorUnordered(Key j1, Key j2, Key j3, Key j4) : Base(j1, j2, j3, j4) {}

    /** Construct 5-way factor */
    SymbolicFactorUnordered(Key j1, Key j2, Key j3, Key j4, Key j5) : Base(j1, j2, j3, j4, j5) {}

    /** Construct 6-way factor */
    SymbolicFactorUnordered(Key j1, Key j2, Key j3, Key j4, Key j5, Key j6) : Base(j1, j2, j3, j4, j5, j6) {}

    /// @}
    
    /// @name Advanced Constructors
    /// @{

    /** Constructor from a collection of keys */
    template<class KeyIterator> SymbolicFactorUnordered(KeyIterator beginKey, KeyIterator endKey) : Base(beginKey, endKey) {}

    /// @}

  private:
    /** Serialization function */
    friend class boost::serialization::access;
    template<class ARCHIVE>
    void serialize(ARCHIVE & ar, const unsigned int version) {
      ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(Base);
    }

  }; // IndexFactor

}
