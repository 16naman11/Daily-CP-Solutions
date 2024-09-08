import datetime

class CarRental:
    def __init__(self):
        self.cars = {'Sedan': 10, 'SUV': 5, 'Hatchback': 7}
        self.rates = {'hourly': 10, 'daily': 50, 'weekly': 200}

    def display_inventory(self):
        for car, count in self.cars.items():
            print(f"{car}: {count}")

    def rent_car(self, car, period, duration):
        if self.cars.get(car, 0) == 0:
            print(f"Sorry, {car} is unavailable.")
            return None
        self.cars[car] -= 1
        print(f"Rented a {car} for {duration} {period}(s).")
        return {'car': car, 'period': period, 'duration': duration, 'start': datetime.datetime.now()}

    def return_car(self, rental):
        self.cars[rental['car']] += 1
        cost = rental['duration'] * self.rates[rental['period']]
        print(f"Total cost: ${cost}")
        return cost

def main():
    rental_service = CarRental()
    rental_info = None

    while True:
        choice = input("\n1. Display cars\n2. Rent a car\n3. Return a car\n4. Exit\nChoice: ")
        if choice == '1':
            rental_service.display_inventory()
        elif choice == '2':
            car = input("Car type: ")
            period = input("Period: ")
            duration = int(input("Duration: "))
            rental_info = rental_service.rent_car(car, period, duration)
        elif choice == '3' and rental_info:
            rental_service.return_car(rental_info)
            rental_info = None
        elif choice == '4':
            break
        else:
            print("Invalid choice or no active rental.")

if __name__ == "__main__":
    main()
