#pragma once

#include <contrib/ydb/library/yql/dq/actors/compute/dq_compute_actor_async_io.h>
#include <contrib/ydb/library/yql/dq/actors/compute/dq_compute_actor.h>
#include <contrib/ydb/library/yql/dq/actors/dq_events_ids.h>
#include <contrib/ydb/library/yql/dq/actors/protos/dq_events.pb.h>
#include <contrib/ydb/library/yql/dq/actors/task_runner/task_runner_actor.h>
#include <contrib/ydb/library/yql/dq/common/dq_common.h>
#include <contrib/ydb/library/yql/dq/actors/compute/dq_checkpoints_states.h>
#include <contrib/ydb/library/yql/dq/runtime/dq_tasks_runner.h>
#include <contrib/ydb/library/yql/dq/runtime/dq_transport.h>

#include <contrib/ydb/library/actors/core/actor_bootstrapped.h>
#include <contrib/ydb/library/actors/core/hfunc.h>
#include <contrib/ydb/library/actors/core/log.h>

namespace NYql {
namespace NDq {

NActors::IActor* CreateDqAsyncComputeActor(const NActors::TActorId& executerId, const TTxId& txId, NDqProto::TDqTask* task,
    IDqAsyncIoFactory::TPtr asyncIoFactory, const NKikimr::NMiniKQL::IFunctionRegistry* functionRegistry,
    const TComputeRuntimeSettings& settings, const TComputeMemoryLimits& memoryLimits,
    const NTaskRunnerActor::ITaskRunnerActorFactory::TPtr& taskRunnerActorFactory,
    ::NMonitoring::TDynamicCounterPtr taskCounters = nullptr,
    const NActors::TActorId& quoterServiceActorId = {},
    bool ownCounters = false);

} // namespace NDq
} // namespace NYql
