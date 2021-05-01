/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int res;
    int getImportance(vector<Employee*> employees, int id) {
        dfs(employees, id);
        return res;
    }

    void dfs(vector<Employee*> employees, int id) {
        for (Employee* employee : employees) {
            if (employee->id == id) {
                res += employee->importance;
                for (int i : employee->subordinates) {
                    dfs(employees, i);
                }
                break;
            }
        }
    }
};