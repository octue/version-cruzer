import wrapper from './dist/wrapper.js';

export async function version(from, to) {
  // We need to pass strings to WebAssembly
  const effective_from = typeof from === 'string' ? from : JSON.stringify(from);
  const effective_to = typeof to === 'string' ? to : JSON.stringify(to);
  return (await wrapper()).version(effective_from, effective_to);
}
