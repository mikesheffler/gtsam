/* ----------------------------------------------------------------------------

 * GTSAM Copyright 2010, Georgia Tech Research Corporation, 
 * Atlanta, Georgia 30332-0415
 * All Rights Reserved
 * Authors: Frank Dellaert, et al. (see THANKS for the full author list)

 * See LICENSE for the license information

 * -------------------------------------------------------------------------- */

/**
 * @file    Factor.cpp
 * @brief   The base class for all factors
 * @author  Kai Ni
 * @author  Frank Dellaert
 * @author  Richard Roberts
 */

// \callgraph

#include <gtsam/inference/FactorUnordered.h>

namespace gtsam {

  /* ************************************************************************* */
  void FactorUnordered::print(const std::string& s = "Factor", const KeyFormatter& formatter = DefaultKeyFormatter) const
  {
    return this->printKeys(s, formatter);
  }

  /* ************************************************************************* */
  void FactorUnordered::printKeys(const std::string& s, const KeyFormatter& formatter) const {
    std::cout << s << " ";
    BOOST_FOREACH(KEY key, keys_) std::cout << " " << formatter(key);
    std::cout << std::endl;
  }

}