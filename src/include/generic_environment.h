//
// Created by Khurram Javed on 2023-06-01.
//

#ifndef INCLUDE_GENERIC_ENVIRONMENT_H_
#define INCLUDE_GENERIC_ENVIRONMENT_H_

#include <vector>

// Define the interface of the nodes
class Node {
  float activation;

public:
  float GetActivation();
};
class RecurrentNode : public Node {
  float residual_sum;
  std::vector<int> incoming_connections;

public:
  void AddConnection(int c);
  RecurrentNode();
};

class TraceNode {
  float update_rate;
  int incoming_node;

public:
  TraceNode(int connection);
};

class InputNode {
public:
  InputNode();
  void SetValue(float val);
};

class GenericEnvironment {
  std::vector<RecurrentNode> list_of_recurrent_nodes;

public:
  void Step(std::vector<float> actions);
  std::vector<float> GetObservation();
};

#endif // INCLUDE_GENERIC_ENVIRONMENT_H_
