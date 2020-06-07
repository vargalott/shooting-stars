#pragma once
#ifndef __M_SINGLETON__
#define __M_SINGLETON__

template <typename SingleInstance>
class MeyersSingleton
{
public:
	MeyersSingleton() = delete;
	MeyersSingleton(MeyersSingleton<SingleInstance> const&) = delete;
	MeyersSingleton(MeyersSingleton<SingleInstance>&&) = delete;
	MeyersSingleton<SingleInstance> const& operator=(MeyersSingleton<SingleInstance> const&) = delete;
	MeyersSingleton<SingleInstance> const& operator=(MeyersSingleton<SingleInstance>&&) = delete;

	[[nodiscard]] static SingleInstance& GetInstance(void)
	{
		static SingleInstance currentInstance;
		return currentInstance;
	};
	template<typename... Args>
	[[nodiscard]] static SingleInstance& GetInstance(Args... args)
	{
		static SingleInstance currentInstance(args...);
		return currentInstance;
	};
};

#endif // !__M_SINGLETON__