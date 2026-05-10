class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        vector<pair<int, double>> cars;
        for (int i = 0; i < n; i++) {
            // Time = (distance to target) / speed
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Sort cars by position descending (closest to target first)
        sort(cars.begin(), cars.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        int fleets = 0;
        double max_time = 0.0;

        for (const auto& car : cars) {
            // If this car takes more time than the fleet in front, 
            // it starts a new fleet.
            if (car.second > max_time) {
                fleets++;
                max_time = car.second;
            }
        }

        return fleets;
    }
};