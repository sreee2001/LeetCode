/* Two SumMar 14 
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        
        map<int, unsigned int> mapIndexer;
        
        // total O( n log n )
        // this step can be optimized to O (n) if we use a true hash_map for integers
        for (unsigned int index = 0; index < numbers.size(); ++index) // n
        {
            mapIndexer[numbers[index]] = index + 1; // log n
        }
        // total n log n
        // this step can be optimized to O (n) if we use a true hash_map for integers
        for (int i = 0; i < numbers.size(); ++i) // n
        {
            map<int, unsigned int>::iterator it = mapIndexer.find(target - numbers[i]); // log n
            
            if (it != mapIndexer.end())
            {
                if (it->second < i + 1)
                {
                    result.push_back (it->second);
                    result.push_back (i + 1);
                }
                else
                {
                    result.push_back (i + 1);
                    result.push_back (it->second);
                }
                break;
            }
        }
        
        return result;
    }
};
