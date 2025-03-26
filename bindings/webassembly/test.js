import test from 'node:test';
import { strict as assert } from 'node:assert';
import { version } from './cruzer.js';

test('const to enum', async (t) => {
  const from = {
    $schema: 'https://json-schema.org/draft/2020-12/schema',
    const: 'foo'
  };

  const to = {
    $schema: 'https://json-schema.org/draft/2020-12/schema',
    enum: [ 'foo', 'bar' ]
  };

  assert.deepStrictEqual(await version(from, to), {
    version: "minor",
    traces: [
      {
        compatibility: "incompatible",
        left: "/const",
        right: "/enum"
      }
    ]
  });
});
