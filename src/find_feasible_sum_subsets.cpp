
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
List find_feasible_sum_subsets(List S, int theta) {
  int numsets = S.size();

  // If there are no sets, return an empty list
  if (numsets == 0) {
    return List::create();
  }

  NumericVector S1 = S[0];
  IntegerVector S1_feasible_ids;

  // Find indices of elements in S1 that are less than or equal to theta
  for (int i = 0; i < S1.size(); ++i) {
    if (S1[i] <= theta) {
      S1_feasible_ids.push_back(i);
    }
  }

  // If there's only one set, create combinations
  List feasible_combs;
  if (numsets == 1) {
    for (int index : S1_feasible_ids) {
      feasible_combs.push_back(NumericVector::create(S1[index]));
    }
  }

  return feasible_combs;
}
