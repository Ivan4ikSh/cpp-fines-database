#pragma once
#include <iostream>

using namespace System;
using namespace System::Data::SqlClient;
using namespace System::Collections::Generic;
using namespace System::Data;

namespace constants {
	struct Date {
		int day;
		int month;
		int year;
	};

	const Date current_date = { 1,2,2024 };

	const uint8_t fine_persent = 10;

	double FinePersent() {
		return static_cast<double>(fine_persent) / 100;
	}
}

namespace commands {
	enum Table {
		ALL, ARTICLE, INTER, PLATE, VIOLATION,
		EVACUATION, FINE
	};
}

namespace domain {
	ref struct FineInfo {
		String^ article;
		String^ fine_name;
		String^ punishment;
		Int32^ need_evacuation;
	};

	ref struct ViolationInfo {
		int violation_id;
		int driver_id;
		int fine_id;
		bool is_evacuated;
		double fine_cost;
	};

	ref struct EvacuationInfo {
		int driver_id;
		int violation_id;
		int evacuation_cost;
		int storage_cost;
	};

	ref struct PaymentInfo {
		int driver_id;
		int type_id;
		int amount_paid;
	};
}