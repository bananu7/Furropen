#pragma once

#include <Furrovine++/TimeSpan.h>
#include <Furrovine++/Stopwatch.h>
#include <Furrovine++/GameTime.h>
#include <Furrovine++/IWindowService.h>
#include <Furrovine++/IGraphicsDeviceService.h>

namespace Furrovine {
	

	class FurrovineGame {
	protected:
		uint64 updateticks, renderticks;
		TimeSpan renderinterval, updateinterval,
			renderdifference, updatedifference,
			lastrenderdifference, lastupdatedifference;
		double rendertolerance, updatetolerance;
		Stopwatch renderstopwatch, updatestopwatch, gamestopwatch;
		bool prerun, running, idling,
			stopupdate, stoprender, haspushedrender, haspushedupdate, doupdate, dorender;
		IGraphicsDeviceService GraphicsService;
		IGraphicsDevice2DService Graphics2DService;
		IWindowService WindowService;
		bool Updatable, Renderable;
		bool FixedUpdateStep, FixedRenderStep;
		bool RenderWhenIdle, UpdateWhenIdle;
		GameTime Time, RenderTime, UpdateTime;

	public:
		
		furrovineapi FurrovineGame( );

		furrovineapi bool Running () const;

		furrovineapi bool Idling () const;

		furrovineapi void TargetTimeStep ( TimeSpan value );

		furrovineapi TimeSpan TargetTimeStep () const;

		furrovineapi void TargetRenderStep ( TimeSpan value );

		furrovineapi TimeSpan TargetRenderStep () const;

		furrovineapi uint64 UpdateTicks ();

		furrovineapi uint64 RenderTicks ();

		furrovineapi void CheckUpdate ( bool obeyrules = true );

		furrovineapi void CheckRender ( bool obeyrules = true );

		furrovineapi virtual void Run ();

		furrovineapi virtual ~FurrovineGame ();

	protected:

		furrovineapi virtual void BeginRun ();

		furrovineapi virtual void EndRun ();

		furrovineapi virtual void Initialize ();

		furrovineapi virtual void Load ();

		furrovineapi virtual void Update ( GameTime& time );

		furrovineapi virtual void Render ( GameTime& time );

		furrovineapi virtual void PreUpdate ();

		furrovineapi virtual void Update ();

		furrovineapi virtual void PostUpdate ();

		furrovineapi virtual bool PreRender ();

		furrovineapi virtual void Render ();

		furrovineapi virtual void PostRender ();

		furrovineapi virtual void Unload( );

		furrovineapi virtual void BeginLoop( );

		furrovineapi virtual void Loop( );

		furrovineapi virtual void EndLoop( );

		furrovineapi virtual void BeginIdle ();

		furrovineapi virtual void Idle ();

		furrovineapi virtual void EndIdle ();

		furrovineapi virtual void Exit ();

	};

}
