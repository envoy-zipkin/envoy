#pragma once

#include "envoy/config/trace/v2/trace.pb.h"

#include "extensions/tracers/zipkin/zipkin_core_types.h"

namespace Envoy {
namespace Extensions {
namespace Tracers {
namespace Zipkin {

/**
 * This class implements a simple buffer to store Zipkin tracing spans
 * prior to flushing them.
 */
class SpanBuffer {
public:
  /**
   * Constructor that creates an empty buffer. Space needs to be allocated by invoking
   * the method allocateBuffer(size).
   */
  SpanBuffer(const envoy::config::trace::v2::ZipkinConfig::CollectorEndpointVersion version)
      : version_(version) {}

  /**
   * Constructor that initializes a buffer with the given size.
   *
   * @param size The desired buffer size.
   */
  SpanBuffer(const envoy::config::trace::v2::ZipkinConfig::CollectorEndpointVersion version,
             uint64_t size)
      : version_(version) {
    allocateBuffer(size);
  }

  /**
   * Allocates space for an empty buffer or resizes a previously-allocated one.
   *
   * @param size The desired buffer size.
   */
  void allocateBuffer(uint64_t size) { span_buffer_.reserve(size); }

  /**
   * Adds the given Zipkin span to the buffer.
   *
   * @param span The span to be added to the buffer.
   *
   * @return true if the span was successfully added, or false if the buffer was full.
   */
  bool addSpan(const Span& span);

  /**
   * Empties the buffer. This method is supposed to be called when all buffered spans
   * have been sent to to the Zipkin service.
   */
  void clear() { span_buffer_.clear(); }

  /**
   * @return the number of spans currently buffered.
   */
  uint64_t pendingSpans() { return span_buffer_.size(); }

  /**
   * @return the contents of the buffer as a stringified array of JSONs, where
   * each JSON in the array corresponds to one Zipkin span.
   */
  std::string toStringifiedJsonArray();

  const zipkin::proto3::ListOfSpans toProto();

  envoy::config::trace::v2::ZipkinConfig::CollectorEndpointVersion version() { return version_; }

private:
  // We use a pre-allocated vector to improve performance
  std::vector<Span> span_buffer_;
  const envoy::config::trace::v2::ZipkinConfig::CollectorEndpointVersion version_;
};

} // namespace Zipkin
} // namespace Tracers
} // namespace Extensions
} // namespace Envoy
