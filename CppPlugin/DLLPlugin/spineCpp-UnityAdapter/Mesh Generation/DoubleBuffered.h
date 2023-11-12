#pragma once

#include <memory>
#include "SpineCppAdapterCore.h"
namespace SpineUnity {

	template<typename T>
	class DoubleBuffered {
	private:
		std::shared_ptr<T> a;
		std::shared_ptr<T> b;
		bool usingA;
	public:
		DoubleBuffered() {
			a = std::make_shared<T>();
			b = std::make_shared<T>();
		}
		DoubleBuffered(const DoubleBuffered&) = delete;
		DoubleBuffered(const DoubleBuffered&&) = delete;

		std::shared_ptr<T> GetCurrent() {
			return usingA ? a : b;
		}

		std::shared_ptr<T> GetNext() {
			usingA = !usingA;
			return usingA ? a : b;
		}
	};

}