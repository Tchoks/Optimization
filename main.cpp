#include <ilcplex/ilocplex.h>

ILOSTLBEGIN

int main(int argc, char **argv) {


    IloEnv env;
    IloModel model(env);
    IloCplex cplex(model);

    IloNumVar x1(env, 0.0, 40.0, ILOFLOAT, "X1");
    IloNumVar x2(env, -10, 20, ILOINT, "X2");

    model.add(x1);
    model.add(x2);

    IloObjective obj(env, x1 + x2, IloObjective::Minimize, "OBJ");
    model.add(obj);

    IloRange ctr1(env, 2, 2.5 * x1 + x2, IloInfinity, "C1");
    IloRange ctr2(env, -IloInfinity, x1 - 3 * x2, 10, "C2");
    model.add(ctr1);
    model.add(ctr2);

    cplex.exportModel("/Users/martin/CLionProjects/Optimization/test.lp");
    cplex.solve();
    cplex.writeSolution("/Users/martin/CLionProjects/Optimization/sol.txt");

    std::cout << " Objectif = " << cplex.getObjValue() << std::endl;
    std::cout << " X1 = " << cplex.getValue(x1) << std::endl;
    std::cout << " X2 = " << cplex.getValue(x2) << std::endl;

    env.end();

    return 0;
}