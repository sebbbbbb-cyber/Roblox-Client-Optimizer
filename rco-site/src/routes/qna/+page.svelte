<script lang="ts">
  import type { AvailableTab } from '../index/Tabs/AvailableTab';
  import Nl from '../index/Tabs/Nl.svelte';
  import TabItem from '../index/Tabs/TabItem.svelte';
  import Tabs from '../index/Tabs/Tabs.svelte';
  let value: AvailableTab = 'What are flags?';
</script>

<svelte:head>
  <title>RCO - FAQ</title>
</svelte:head>

<main>
  <div class="tabs">
    <Tabs bind:value>
      <TabItem currentTab={value} tab={'Is RCO Safe?'}>
        <p>
          Yes, RCO is safe.<br />
          Outside of our CDN (see
          <a
            href="https://github.com/L8X/Roblox-Client-Optimizer/tree/main#gdpr-ccpa--coppa-disclosure"
            >GDPR/CCPA/COPPA Disclosure</a
          >), we do not collect any data about you.<br />
          In addition, we don't include any malicious code of any kind.<br />
          Don't believe us? <a href="/source">Read the Source Code</a> - we're FOSS!
        </p>
      </TabItem>
      <TabItem currentTab={value} tab={'What are flags?'}>
        <p>
          The Roblox engine uses a system called fast flags as part of the
          deployment process.<br />
          When code is shipped, not all of it is active by default.<br />
          Rather, the changes are enabled and disabled dynamically via FFlags, even
          after the code is live in production.<br />
          We welcome you to read more about flags
          <a href="https://devforum.roblox.com/t/254517">here</a>
          and
          <a href="https://github.com/MaximumADHD/Roblox-FFlag-Tracker">here</a
          >.
        </p>
      </TabItem>
      <TabItem currentTab={value} tab={'Will I get banned for using this?'}>
        <p>
          No, our operations are fully compliant with the <a
            href="https://help.roblox.com/hc/articles/115004647846-Roblox-Terms-of-Use"
            >Roblox Terms of Use</a
          >,<br />
          and we use a method that Roblox themselves intentionally added to the client
          to modify flags.<Nl />
          Roblox Client Optimizer remains operational regardless of anti-cheat measures,
          as we do not inject a DLL nor modify live client memory - our software
          is not an exploit, or a tool used to aid in exploiting.
        </p>
      </TabItem>
      <TabItem
        currentTab={value}
        tab={'Will the software slow down my computer?'}
      >
        <p>
          No, the software is very lightweight and only checks for updates to
          our flag list and updates to itself.<Nl />
          Additionally, we use a content delivery network powered by
          <a href="https://www.fastly.com/">Fastly</a> to optimize the bandwidth
          usage and file size of any request(s) that the software makes.
        </p>
      </TabItem>
      <TabItem currentTab={value} tab={'Why not manually install flags?'}>
        <p>
          Manually installing flags is time consuming.<br />
          When Roblox updates, you must remember to install the flag file manually
          again,<br />while Roblox Client Optimizer will handle this operation
          automatically.<Nl />
          In addition, if a major bug is found within the flag file, there is no
          way for us to notify you to update it,<br />therefore we've
          implemented measures to automatically update our flag list if such a
          problem arose.
        </p>
      </TabItem>
    </Tabs>
  </div>
</main>

<style lang="scss">
  main {
    text-align: center;
    h1,
    h2,
    h3,
    h4,
    h5,
    h6 {
      margin: 0;
    }
    h6 {
      font-weight: 400;
      color: #888888;
    }
    .tabs {
      max-width: 1000px;
      p {
        margin: 0;
      }
    }
  }
</style>
